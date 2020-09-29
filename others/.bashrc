stty -ixon
shopt -s autocd
shopt -s cdspell
shopt -s checkwinsize
shopt -s dirspell
shopt -s expand_aliases
PS1="\T \[$(tput sgr0)\]\[\033[38;5;10m\]\w\[$(tput sgr0)\]\[\033[38;5;15m\]>\[$(tput sgr0)\]"
force_color_prompt=yes
HISTCONTROL=ignoreboth
shopt -s histappend
HISTSIZE=1000
HISTFILESIZE=2000
#alias ls="ls -a --color=auto --group-directories-first"
alias ls="exa --group-directories-first --git-ignore"
alias la="exa --group-directories-first -a"
alias ld="exa -D"
alias grep='grep --color=auto'
alias h="cdf ~"
alias mkdir="mkdir -p"
alias wget='wget --hsts-file="$XDG_CACHE_HOME/wget-hsts'
alias sdl="shred -vfzu -n 24"
alias sl="ls"
alias psm="sudo ps_mem"
alias ffmpeg="ffmpeg -hide_banner"
alias detox="detox -vrs lower --remove-trailing "
alias gp="git push origin master"
alias c='cdf "$(fd --type d . /home/dgu | fzf)"'
alias ddf='fdupes . -rdN'
alias gm='git add . && git commit -m '
alias cop="sudo rm config.h; rm *.orig; rm *.rej; sudo make clean"
alias hisc="history -c"
alias unlock="git config credential.helper store"
alias def="find . -type d -empty -print -delete"
alias rml="sudo reflector --latest 5 --sort rate --save /etc/pacman.d/mirrorlist && sudo pacman -Syyu"
alias nowallpaper="xsetroot -solid '#282828'"
alias pm="sudo pacman -Syu --overwrite='*'"
alias unlockupdates="sudo rm -r /var/lib/pacman/db.lck"
alias j="sudo rm config.h; rm *.orig; rm *.rej; sudo make clean; sudo make clean install;"
alias bp="ln -s ~/dotfiles/others/.profile ~/.bash_profile"
alias lc="ls | wc -l"
alias cam="mpv /dev/video0"
alias screenbrigh="xrandr --output eDP-1 --brightness "
alias bsu="bspc wm -r"
alias sxhu="pkill -USR1 -x sxhkd"
function vf(){
	fd --type f . '/home/dgu' | fzf | xargs -r -I {} ~/dotfiles/exts/v "{}"
}

function cdf(){
		builtin cd "$1"; ls --color=auto --group-directories-first;
}

function cleanlinks(){
	find . -type l -xtype l | xargs -r -I {} rm "{}"
}

function ees(){
	find ~/dotfiles/exts -type f |fzf --preview 'head -50 {}' | xargs -r nvim
}

function ee(){
	find ~/dotfiles -type f | grep -v ".git\|.exts\|.png\|Makefile\|util.h\|LICENSE\|.mk\|.1\|.info\|util.c" | fzf --preview 'head -50 {}' | xargs -r -I {} nvim "{}"
}

function cleangit(){
	git checkout --orphan temp_branch;git add -A; git commit -am "history deleted"; git branch -D master; git branch -m master; git push -f origin master
}
function createwallpape(){
		convert -size 1920x1080 "xc:#282828" -gravity center -pointsize 93 -weight 700 -fill "#bbbbbb" -annotate 0 "$(echo "Type in the message" | dmenu -p -i -l 5)" ~/.config/wall.jpg && feh --bg-scale ~/.config/wall.jpg
}

function webptojpg(){
		for i in *.webp;do convert "$i" "$i.jpg"; done
		rm *.webp
}
