
ABOUT
-----

This is a base theme designed for the Panels Everywhere module. It builds upon
a grid framework similar to the 960.gs project. The biggest difference is that
this grid system is more fine grained with 48 to 65 columns. Each column is
10 pixels wide with 10 pixels gutter. The default 48 column version is 960
pixels wide, the 49 column version is 980 pixels wide, the 50 column version is
1000 pixels wide and the 65 column version is 1300 pixels wide.

USAGE
-----
- Download and enable ctools, panels and panels everywhere.
- Activate panels everywhere site template in: "/admin/structure/panels/settings/everywhere"
- Enable site template in http://loc.sand.box/admin/structure/pages and choose "precision site template" under layout.

Note: Panels everywhere is best used together with views content pane display.

It's important that you use the layout "Precision site template", as the
layout for the panel "Site template". If your site doesn't center properly,
you've probably missed this.

To make custom pages, you use the other precision layouts. Site template only works as a site template.

You can choose to use the precision grid styles on single panes to do custom layout of panes within a region. This is done by clicking the setting icon on each pane and choosing it under the style section in the dropdown.

SETTINGS
--------
Under appearance you can choose to enable the debug overlay which allows you to hover the cursor over grid elements to highlight it and see the width for it.

You can also select to use the reset.css that basically removes most styling on standard elements like tables and inputs.

EXTEND
------
A example sub theme come with precision to show how you can create your own templates and style with precision as the base theme.
