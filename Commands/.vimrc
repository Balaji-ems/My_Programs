set nu
set smartindent
set autoindent
set cindent
set showmode

filetype off
set rtp+=~/.vim/bundle/Vundle.vim
call vundle#begin()
Plugin 'VundleVim/Vundle.vim'
Plugin 'junegunn/seoul256.vim'
Plugin 'junegunn/goyo.vim'
Plugin 'junegunn/limelight.vim'
call vundle#end()
filetype plugin indent on
syntax enable

set dictionary=/usr/share/dict/words

# to use dictionary completion use ctrl+k or ctrl+x
