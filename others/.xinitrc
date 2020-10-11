source /etc/X11/xinit/xinitrc.d/40-libcanberra-gtk-module.sh
xrdb -merge $HOME/.Xresources
xmodmap $HOME/.Xmodmap
setxkbmap -layout br &
sudo ntpdate 0.br.pool.ntp.org
xsetroot -cursor_name arrow &
numlockx on &
qjackctl &
~/dotfiles/exts/setbg
#megasync &
polybar -r bar &
sxhkd &
bspwm
