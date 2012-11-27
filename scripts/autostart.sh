#!/bin/bash

### Autostart example script
### could be placed in .config/dwm/ directory

# dropbox
~/.dropbox-dist/dropboxd &

# network
wicd-client &

# background image
fbsetbg ~/images/meme-debian-squeeze-tux-planet-90199.jpg &

# settings
xset b off &
# Key binding
xmodmap ~/.Xmodmap &

# Screensaver
xscreensaver -no-splash &

