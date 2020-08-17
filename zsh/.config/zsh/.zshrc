autoload -U colors && colors
PROMPT="%F{34}%~%f> "
RPROMPT="%*(%?)"

HISTFILE=~/.cache/zsh/history
HISTSIZE=10000
SAVEHIST=10000

autoload -U compinit
zstyle ':completion:*' menu select
zmodload zsh/complist
compinit
_comp_options+=(globdots)		# Include hidden files.

alias -s jpg=sxiv
alias -g L="| wc -l"

alias ls="exa --group-directories-first --git-ignore"
alias la="exa --group-directories-first -a"
alias ld="exa -D"
alias grep='grep --color=auto'
alias h="cdf ~"
alias mkdir="mkdir -p"
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
function createwallpaper(){
		convert -size 1920x1080 "xc:#282828" -gravity center -pointsize 93 -weight 700 -fill "#bbbbbb" -annotate 0 "$(echo "Type in the message" | dmenu -p -i -l 5)" ~/.config/wall.jpg && feh --bg-scale ~/.config/wall.jpg
}

function v(){
		~/dotfiles/exts/v $1 &
}
