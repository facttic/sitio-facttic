<?php

// Argentina

function location_province_list_ar() {
  return array('A' => "Salta",
    'B' => "Buenos Aires",
    'C' => "C.A.B.A.",
    'D' => "San Luis",
    'E' => "Entre Ríos",
    'F' => "La Rioja",
    'G' => "Santiago del Estero",
    'H' => "Chaco",
    'J' => "San Juan",
    'K' => "Catamarca",
    'L' => "La Pampa",
    'M' => "Mendoza",
    'N' => "Misiones",
    'P' => "Formosa",
    'Q' => "Neuquén",
    'R' => "Rio Negro",
    'S' => "Santa Fe",
    'T' => "Tucumán",
    'U' => "Chubut",
    'V' => "Tierra del Fuego",
    'W' => "Corrientes",
    'X' => "Córdoba",
    'Y' => "Jujuy",
    'Z' => "Santa Cruz");
}

/**
 * Returns minimum and maximum latitude and longitude needed to create a bounding box.
 */
function location_bounds_ar() {
  return array(
    'minlng' => -73.4967,
    'minlat' => -55.049767,
    'maxlng' => -53.64205,
    'maxlat' => -21.829967,
  );
}
