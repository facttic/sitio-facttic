#!/bin/bash

# deploy.sh 
# Setear los datos necesarios en las líneas siguientes.
# Copiar afuera del repo y usar
#    sh deploy.sh [clone] [no-backup]
#
# Usar parametro clone para borrar el repo y clonarlo de nuevo
# Usar parametro no-backup para no hacer un backup de la base de datos antes de borrarla
#
user="" # Setear el nombre de usuario de git
site="" # Setear el nombre del repo (también se usa como nombre de la base de datos)
DB_HOST="localhost"
DB_NAME=$site
DB_USER="root" # Setear usuario de la base de datos
DB_PASS="" # Setear pass de la base de datos

drush=/root/drush/drush # Ruta a drush

# # # # # #

clone=0
backup=1

if [ $1 ]; then
  if [ $1 = "clone" ]; then
    clone=1
  else 
    if [ $1 = "no-backup" ]; then
      backup=0
    fi
  fi
  if [ $2 ]; then
    if [ $2 = "clone" ]; then
      clone=1
    else 
      if [ $2 = "no-backup" ]; then
        backup=0
      fi
    fi
  fi
fi

if [ $clone -eq 1 ];then
  echo "Se eliminará y clonará el repo"
fi
if [ $backup -eq 0 ];then
  echo "No se hará backup de la base de datos"
fi


# Si hay que clonar borramos y clonamos el repo
if [ $clone -eq 1 ]; then
  echo "Eliminando y clonando nuevamente el repositorio"
  if [ -d $site ]; then
    echo "Borrando $site"
    rm -rf $site
  fi

  echo "Clonando $site"
  git clone ssh://$user@git.gcoop.com.ar/var/git/$site.git
fi

# Backup de la base de datos
if [ $backup -eq 1 ]; then
  echo "Haciendo backup de la base de datos"
  pushd .
  cd $site
  $drush bam-backup
  popd
fi


#copiar default.settings.php a settings.php editando la conexion a la db 
conf_db="\$databases = array \(\
  'default' => \
  array \(\
    'default' => \
    array \(\
      'database' => '$DB_NAME',\
      'username' => '$DB_USER',\
      'password' => '$DB_PASS',\
      'host' => '$DB_HOST',\
      'port' => '',\
      'driver' => 'mysql',\
      'prefix' => '',\
    \),\
  \),\
\);"


echo "Copiando default.settings.php a settings.php"
echo "Conexión a la db: $conf_db"
sed "180s/.*/$conf_db/" $site/sites/default/default.settings.php > $site/sites/default/settings.php
chmod go-w $site/sites/default/settings.php

#crear directorio files
echo "Creando directorio sites/default/files"
mkdir -p $site/sites/default/files
chmod a+w $site/sites/default/files
#crear directorio tmp
echo "Creando directorio sites/default/tmp"
mkdir -p $site/sites/default/tmp
chmod a+w $site/sites/default/tmp
chgrp www-data $site/private -R

#restaurar la base de datos inicial 
echo "Drop database anterior"
echo "DROP database $DB_NAME;" | mysql -h $DB_HOST --user=$DB_USER --password=$DB_PASS
echo "Create database"
echo "CREATE database $DB_NAME;" | mysql -h $DB_HOST --user=$DB_USER --password=$DB_PASS
#restaurar la base de datos inicial 
echo "Restaurando la base de datos inicial"
db_file=$site/tools/database-inicial.sql
gunzip $db_file.gz
mysql -h $DB_HOST --user=$DB_USER --password=$DB_PASS --database=$DB_NAME < $db_file
gzip $db_file

# Entro a $site para poder ejecutar linea drush
cd $site
#habilitar modulos
echo "Habilitando módulos"
dir_modulos="tools/listados-modulos"
for f in $(ls $dir_modulos); do
  xargs -a $dir_modulos/$f $drush en -y
done;

#habilitar features
echo "Habilitando features"
dir_features="sites/all/modules/gcoop_features"
ls $dir_features | xargs $drush en -y

#revert features
echo "Revert features"
$drush features-revert-all -y

echo "Traducimos la interfaz"
$drush -i drush_commands language-disable en
$drush l10n-update --languages=es

##traduccion (si no se puede usar l10n_update por tener la version de atrium)
#echo "Traducimos módulos"
#$drush en glang -y
#$drush dis glang -y
#$drush pm-uninstall glang -y

echo "Importamos los nodos"
for f in $(ls node-export/*.export); do 
  echo "Importando $f"
  $drush ne-import --file=$f; 
done;

#echo "Creamos usuarios"
#$drush user-create editor1 --password="gc00p" --mail="a@a.com"
#$drush user-add-role editor editor1

echo "Ejecutamos cron"
$drush cron

# Borrar .git
# Borrar directorios de modulos contrib NO usados
