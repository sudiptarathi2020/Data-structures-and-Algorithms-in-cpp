set tabstop=4
set nocompatible
set shiftwidth=4
set expandtab
set autoindent
set smartindent
set ruler
set showcmd
set incsearch
set shellslash
set number
set backspace=indent,eol,start
set relativenumber
set cino+=L0 
set clipboard=unnamedplus
syntax on
filetype indent on
filetype off
setlocal indentkeys-=:
set background=dark
inoremap {<CR>  {<CR>}<Esc>O
inoremap {}     {}
inoremap ()     ()
inoremap []     []
imap jk         <Esc>
map <C-a> <esc>ggVG<CR>
set belloff=all
autocmd BufNewFile *.cpp 0r /home/sudipta/cpp/template/template.cpp
autocmd filetype cpp nnoremap <F9> :w <bar> !g++ -std=c++17 -O2 -Wall % -o %:r.out <CR>
autocmd filetype cpp nnoremap <F12> :!./%:r.out<CR>
autocmd FileType python map <buffer> <F9> :w<CR>:exec '!python3' shellescape(@%, 1)<CR>
autocmd FileType python imap <buffer> <F9> <esc>:w<CR>:exec '!python3' shellescape(@%, 1)<CR>
autocmd filetype c nnoremap <F9> :w <bar> !gcc -lm -lpthread % -o %:r.out <CR>
autocmd filetype c nnoremap <F12> :!./%:r.out<CR>
autocmd FileType tex :NoMatchParen
autocmd FileType tex :set tw=110
set rtp+=~/.vim/bundle/Vundle.vim
call vundle#begin()
Plugin 'VundleVim/Vundle.vim'
Plugin 'lervag/vimtex'
Plugin 'octol/vim-cpp-enhanced-highlight'
Plugin 'jiangmiao/auto-pairs'
Plugin 'altercation/vim-colors-solarized'
Plugin 'ShowPairs'
Plugin 'vim-airline/vim-airline'
Plugin 'morhetz/gruvbox'
Plugin 'pangloss/vim-javascript'
Plugin 'othree/html5.vim'
Plugin 'valloric/youcompleteme'
call vundle#end()
filetype plugin indent on
let g:vimtex_view_general_viewer = 'SumatraPDF'
let g:vimtex_view_general_options = '-reuse-instance @pdf'
let g:vimtex_view_general_options_latexmk = '-reuse-instance'
let g:tex_flavor = 'latex'
let g:vimtex_motion_matchparen = 0
let g:vimtex_fold_manual = 1
let g:vimtex_matchparen_enabled = 0
" Let clangd fully control code completion
let g:ycm_clangd_uses_ycmd_caching = 0
" Use installed clangd, not YCM-bundled clangd which doesn't get updates.
let g:ycm_clangd_binary_path = exepath("clangd")
set t_Co=256
colorscheme gruvbox
nnoremap <silent> [oh :call gruvbox#hls_show()<CR>
nnoremap <silent> ]oh :call gruvbox#hls_hide()<CR>
nnoremap <silent> coh :call gruvbox#hls_toggle()<CR>

nnoremap * :let @/ = ""<CR>:call gruvbox#hls_show()<CR>*
nnoremap / :let @/ = ""<CR>:call gruvbox#hls_show()<CR>/
nnoremap ? :let @/ = ""<CR>:call gruvbox#hls_show()<CR>? 

set completeopt-=preview
