# Junction Shell Extensions
Windows Explorer shell extensions for adding a tooltip overlay on symbolic links.

[I originally released this in 2005](http://www.paraesthesia.com/archive/2005/04/20/junction-shell-extensions.aspx/) as an aid in visually distinguishing real folders and files from symbolic links in Windows Explorer.

It has since been superseded by [Hermann Schinagl's Link Shell Extension](http://schinagl.priv.at/nt/hardlinkshellext/hardlinkshellext.html) which has incorporated the icon overlay and has many, many more features.

In the code here you'll find...

- JunctionIconOverlay - The icon overlay extension.
- JunctionIconOverlaySetup - The setup project that installs all junction-related extensions.
- JunctionIconTooltip - A sample tooltip provider that could be adapted to show the destination of a junction.  Not used because I can't figure out how to only enable it for junctions.