#!/bin/bash
PATH=$PATH:~/exts

QT_QPA_PLATFORMTHEME=""
QT_STYLE_OVERRIDE=""

export PATH=~/dotfiles/exts:$PATH
[ -f /.bashrc ] && source ~/.bashrc

if  [ "$(tty)" = "/dev/tty1" ]; then
		pgrep sxhkd | exec startx
fi
