let mapleader="+"
let g:table_mode_corner='|'
if empty(glob('~/.vim/autoload/plug.vim'))
  silent !curl -fLo ~/.vim/autoload/plug.vim --create-dirs
    \ https://raw.githubusercontent.com/junegunn/vim-plug/master/plug.vim
  autocmd VimEnter * PlugInstall --sync | source $MYVIMRC
endif
call plug#begin('~/.vim/plugged')
Plug 'ap/vim-css-color'
Plug 'dhruvasagar/vim-table-mode'
Plug 'dracula/vim'
Plug 'junegunn/goyo.vim'
Plug 'kovetskiy/sxhkd-vim'
Plug 'triglav/vim-visual-increment'
call plug#end()

color dracula

set bg=dark
set clipboard+=unnamedplus
set clipboard=unnamed
set complete+=k
set encoding=utf-8
set expandtab
set go=a
set hlsearch
set incsearch
set lazyredraw
set mouse=a
set noexpandtab
set nohlsearch
set nomore
set noshowmode
set nrformats=alpha
set relativenumber
set showmatch
set sidescroll=1
set softtabstop=4
set splitbelow splitright
set synmaxcol=500
set tabstop=4
set termguicolors
set wildmenu
set wildmode=longest,list,full

filetype indent on
hi CursorLineNr ctermfg=Green
hi QuickFixLine term=reverse ctermbg=52
syntax on

imap ;null >/dev/null 2>&1
imap ;ssh #!/bin/sh
inoremap <F2> <C-X><C-K>
map <C-k> "+P
map <Leader>c 1z=
map <Leader>n :noh<CR>
map <Leader>o z=
map <leader>e :silent! !chmod 777 %<CR>
map <leader>q :q!<CR>
map <leader>w :w!<CR>
vnoremap <C-c> "*y :let @+=@*<CR>


autocmd FileType * setlocal formatoptions-=c formatoptions-=r formatoptions-=o
autocmd BufWritePost *.Xresources,*Xdefaults !xrdb ~/.Xresources
autocmd BufWritePost *bspwmrc :silent! !bspc wm -r &
autocmd BufWritePost *dunstrc :silent! !killall dunst &
autocmd BufWritePost *sxhkdrc :silent! !pkill -USR1 -x sxhkd &
autocmd BufWritePre * $put _ | $;?\(^\s*$\)\@!?+1,$d
autocmd BufWritePre * :silent! %s/\s\+$//e
