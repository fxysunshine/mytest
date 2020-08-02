" Configuration file for vim
set modelines=0		" CVE-2007-2438

" Normally we use vim-extensions. If you want true vi-compatibility
" remove change the following statements
set nocompatible	" Use Vim defaults instead of 100% vi compatibility
set number
set relativenumber  "rnu/nornu
"set mouse=a
"set selection=exclusive 
"set selectmode=mouse,key

"set scrolloff=12

"scheme can be peaksea,ir_black,solarized,ptye,mayansmoke
"colorscheme peaksea 
"colorscheme desert
set t_Co=256
"colorscheme molokai
"let g:molokai_original = 1
"let g:rehash256 = 1

"set completeopt-=preview

" Don't write backup file if vim is being called by "crontab -e"
au BufWrite /private/tmp/crontab.* set nowritebackup nobackup
" Don't write backup file if vim is being called by "chpass"
au BufWrite /private/etc/pw.* set nowritebackup nobackup

""""""""""""""""""""""""""""""
" Vundle.vim
""""""""""""""""""""""""""""""
filetype off                  " required

" set the runtime path to include Vundle and initialize
set rtp+=~/.vim_runtime/my_plugins/bundle/Vundle.vim
set rtp+=~/.fzf
"call vundle#begin()
" alternatively, pass a path where Vundle should install plugins
call vundle#begin('~/.vim_runtime/my_plugins/bundle')

" let Vundle manage Vundle, required
Plugin 'VundleVim/Vundle.vim'

Plugin 'Shougo/vimproc.vim'
Plugin 'easymotion/vim-easymotion'
Plugin 'mbbill/undotree'
Plugin 'fxysunshine/taglist.vim'
Plugin 'Yggdroot/LeaderF'
Plugin 'simplyzhao/cscope_maps.vim'
Plugin 'vim-scripts/grep.vim'
Plugin 'fxysunshine/mark.vim'
Plugin 'Valloric/YouCompleteMe'
Plugin 'SirVer/ultisnips'
Plugin 'junegunn/fzf.vim'
Plugin 'kshenoy/vim-signature'
Plugin 'liuchengxu/vim-which-key'
Plugin 'brtastic/vim-jsonviewer'

" All of your Plugins must be added before the following line
call vundle#end()            " required

filetype plugin indent on    " required

let g:go_fmt_command = "goimports"
let g:go_version_warning = 0

set history=1000
"set cursorline
set tabstop=4
set softtabstop=4
"set paste

set splitbelow
set splitright
set cindent
set tags=tags;

filetype indent on
autocmd FileType python setlocal et sta sw=4 sts=4

autocmd BufReadPost * if line("'\"") && line("'\"") <= line("$") | exe "normal `\"" | endif

let &termencoding=&encoding
set fileencodings=utf-8,gbk
set backspace=indent,eol,start

let g:peepopen_loaded=1

""""""""""""""""""""""""""""""
" Vimshell
""""""""""""""""""""""""""""""
"nnoremap <F4> :VimShellPop<CR>
"inoremap <F4> <Esc>:VimShellPop<CR>
"let g:vimshell_popup_command = 'vsplit'
"let g:vimshell_prompt = 'shine%'
"let g:vimshell_editor_command = 'vim'

""""""""""""""""""""""""""""""
" Tlist
""""""""""""""""""""""""""""""
let Tlist_Show_One_File=1
let Tlist_Exit_OnlyWindow=1
let Tlist_Use_Right_Window=1
let Tlist_Ctags_Cmd="/usr/bin/ctags"
nnoremap <silent> <F10> :TlistToggle<CR>
"nnoremap <silent> <F12> :!ctags -R --c++-kinds=+p --fields=+iaS --extra=+q --exclude=prepare-commit-msg .<CR>

nmap <C-]> g]

""""""""""""""""""""""""""""""""
" NERDTree settings
""""""""""""""""""""""""""""""""
map <Leader>tt :NERDTreeToggle<CR>
nnoremap <silent> <F4> :NERDTreeFind<CR>
map <Leader>nb :NERDTreeFromBookmark<CR>
map <Leader>nn :NERDTreeFind<CR>
map <Leader>nc :NERDTreeClose<CR>
nnoremap <silent> <F5> :NERDTreeClose<CR>
let NERDTreeWinSize=32
let NERDTreeWinPos="left"
let NERDTreeIgnore=['\~$', '\.pyc$', '\.swp$', '\.git$']
let NERDTreeShowBookmarks=1
"let NERDTreeShowHidden=1
let NERDTreeMinimalUI=1
let NERDTreeAutoDeleteBuffer=1

"nmap <C-j> <C-d>
"nmap <C-k> <C-u>

""""""""""""""""""""""""""""""""""""
" WinManager setting, F9+F10?
""""""""""""""""""""""""""""""""""""
"let g:winManagerWindowLayout='FileExplorer|TagList'
"nmap wm :WMToggle<cr>

""""""""""""""""""""""""""""""""
"-- Rgrep setting --
""""""""""""""""""""""""""""""""
"nnoremap <silent> <F5> :Rgrep<CR>
let Grep_Default_Options = '-i'
let Grep_Skip_Dirs = '.git .repo tests test'
let Grep_Skip_Files = '*.bak *~ cscope.* tags *.swp *.so'
let Grep_Default_Filelist = '*.[chS] *.cc *.cpp *.asm *.java *.mk'

""""""""""""""""""""""""""""""""
"-- MiniBufExplorer setting --
""""""""""""""""""""""""""""""""
"let g:miniBufExplMapCTabSwitchBufs = 1
"let g:miniBufExplMapWindowNavArrows = 1

""""""""""""""""""""""""""""""""
"-- quickfix setting --
""""""""""""""""""""""""""""""""
"-- :cnext or :cn and :cprev or :cp commands jump to the next or previous output line
"nnoremap <silent> <C-j> :cnext<CR>
"nnoremap <silent> <C-k> :cprev<CR>
"nnoremap <silent> <F6> :copen<CR>
"nnoremap <silent> <F7> :cclose<CR>

"-- switch between multi windows --
"nnoremap <silent> <F2> <C-w><C-w>
"nnoremap <silent> <F3> <C-w><C-c>
"nnoremap <silent> <F4> <C-w><C-o>
"nnoremap <silent> <F8> <leader>m   ----> that has done in mark.vim


""""""""""""""""""""""""""""""
" tmp max current windows
""""""""""""""""""""""""""""""
function! Zoom()
    " check if is the zoomed state (tabnumber > 1 && window == 1)
    if tabpagenr('$') > 1 && tabpagewinnr(tabpagenr(), '$') == 1
        let l:cur_winview = winsaveview()
        let l:cur_bufname = bufname('')
        tabclose

        " restore the view
        if l:cur_bufname == bufname('')
            call winrestview(cur_winview)
        endif
    else
        tab split
    endif
endfunction

nmap <leader>m :call Zoom()<CR>
nmap <leader>i :call jsonviewer#init()<CR>

"""""""""""""""""""""""""""""""""""""""""""
" clean empty buffers and remain only one tabs
"""""""""""""""""""""""""""""""""""""""""""
function! CleanEmptyBuffersAndTabs()
    let buffers = filter(range(1, bufnr('$')), 'buflisted(v:val) && empty(bufname(v:val)) && bufwinnr(v:val)<0 && !getbufvar(v:val, "&mod")')
    if !empty(buffers)
        exe 'bw ' . join(buffers, ' ')
    endif
    exe 'tabonly'
endfunction
nmap <leader>k :call CleanEmptyBuffersAndTabs()<CR>

""""""""""""""""""""""""""""""
" leaderf setting
""""""""""""""""""""""""""""""
nmap <silent> <leader>lf :LeaderfFile<cr>
nmap <silent> <leader>lb :LeaderfBuffer<cr>

""""""""""""""""""""""""""""""
" undotree setting
""""""""""""""""""""""""""""""
if has("persistent_undo")
  set undodir=~/.undodir/
  set undofile
endif

nnoremap <leader>u :UndotreeToggle<cr>

""""""""""""""""""""""""""""""
" easy-motion setting
""""""""""""""""""""""""""""""
" <Leader>f{char} to move to {char}
map  f <Plug>(easymotion-bd-f)
nmap f <Plug>(easymotion-overwin-f)

nmap <leader>r :cs find t

"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" => Vim-go
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
let g:ale_linters = {
\   'javascript': ['jshint'],
\   'python': ['flake8'],
\   'go': ['go', 'errcheck']
\}

let g:loaded_comfortable_motion = 0

""""""""""""""""""""""""""""""
" ycm & UltiSnips
""""""""""""""""""""""""""""""
let g:ycm_key_list_select_completion = ['<c-n>', '<Down>']
let g:ycm_key_list_previous_completion = ['<c-p>', '<Up>']
let g:UltiSnipsExpandTrigger="<tab>"

""""""""""""""""""""""""""""""
" fzf
""""""""""""""""""""""""""""""
"<Leader>c在当前目录搜索文件
nnoremap <silent> <Leader>c :Files<CR>
"<Leader>b切换Buffer中的文件
"nnoremap <silent> <Leader>b :Buffers<CR>
"<Leader>p在当前所有加载的Buffer中搜索包含目标词的所有行，:BLines只在当前Buffer中搜索
"nnoremap <silent> <Leader>p :Lines<CR>
"<Leader>h在Vim打开的历史文件中搜索，相当于是在MRU中搜索，:History：命令历史查找
"nnoremap <silent> <Leader>h :History<CR>
"调用Rg进行搜索，包含隐藏文件
command! -bang -nargs=* Rg
  \ call fzf#vim#grep(
  \   'rg --column --line-number --no-heading --color=always --smart-case '.shellescape(<q-args>), 1,
  \   <bang>0 ? fzf#vim#with_preview('up:60%')
  \           : fzf#vim#with_preview('right:50%:hidden', '?'),
  \   <bang>0)


""""""""""""""""""""""""""""""
" ack/rg
""""""""""""""""""""""""""""""
if executable('rg')
  let g:ackprg = 'rg --vimgrep -Tjs -Tsql'
endif
let g:ackhighlight = 1
"let g:ack_autoclose = 1
let g:ack_use_cword_for_empty_search = 1

""""""""""""""""""""""""""""""
" vim-which-key
""""""""""""""""""""""""""""""
let g:mapleader = "\<Space>"
let g:maplocalleader = ","

nnoremap <silent> <leader> :WhichKey '<Space>'<CR>
nnoremap <silent> <localleader> :WhichKey ','<CR>

let g:which_key_map =  {}

" `name` 是一个特殊字段，如果 dict 里面的元素也是一个 dict，那么表明一个 group，比如 `+file`, 就会高亮和显示 `+file` 。默认是 `+prefix`.

" =======================================================
" 基于已经存在的快捷键映射，直接使用一个字符串说明介绍信息即可
" =======================================================
" You can pass a descriptive text to an existing mapping.

let g:which_key_map.f = { 'name' : '+file' }

nnoremap <silent> <leader>fs :update<CR>
let g:which_key_map.f.s = 'save-file'

nnoremap <silent> <leader>fd :e $MYVIMRC<CR>
let g:which_key_map.f.d = 'open-vimrc'

nnoremap <silent> <leader>oq  :copen<CR>
nnoremap <silent> <leader>ol  :lopen<CR>
let g:which_key_map.o = {
      \ 'name' : '+open',
      \ 'q' : 'open-quickfix'    ,
      \ 'l' : 'open-locationlist',
      \ }

" =======================================================
" 不存在相关的快捷键映射，需要用一个 list：
" 第一个元素表明执行的操作，第二个是该操作的介绍
" =======================================================
" Provide commands(ex-command, <Plug>/<C-W>/<C-d> mapping, etc.) and descriptions for existing mappings
let g:which_key_map.b = {
      \ 'name' : '+buffer' ,
      \ '1' : ['b1'        , 'buffer 1']        ,
      \ '2' : ['b2'        , 'buffer 2']        ,
      \ 'd' : ['bd'        , 'delete-buffer']   ,
      \ 'f' : ['bfirst'    , 'first-buffer']    ,
      \ 'h' : ['Startify'  , 'home-buffer']     ,
      \ 'l' : ['blast'     , 'last-buffer']     ,
      \ 'n' : ['bnext'     , 'next-buffer']     ,
      \ 'p' : ['bprevious' , 'previous-buffer'] ,
      \ '?' : ['Buffers'   , 'fzf-buffer']      ,
      \ }

let g:which_key_map.l = {
      \ 'name' : '+lsp'                                            ,
      \ 'f' : ['LanguageClient#textDocument_formatting()'     , 'formatting']       ,
      \ 'h' : ['LanguageClient#textDocument_hover()'          , 'hover']            ,
      \ 'r' : ['LanguageClient#textDocument_references()'     , 'references']       ,
      \ 'R' : ['LanguageClient#textDocument_rename()'         , 'rename']           ,
      \ 's' : ['LanguageClient#textDocument_documentSymbol()' , 'document-symbol']  ,
      \ 'S' : ['LanguageClient#workspace_symbol()'            , 'workspace-symbol'] ,
      \ 'g' : {
        \ 'name': '+goto',
        \ 'd' : ['LanguageClient#textDocument_definition()'     , 'definition']       ,
        \ 't' : ['LanguageClient#textDocument_typeDefinition()' , 'type-definition']  ,
        \ 'i' : ['LanguageClient#textDocument_implementation()'  , 'implementation']  ,
        \ },
      \ }

call which_key#register('<Space>', "g:which_key_map")
nnoremap <silent> <leader> :<c-u>WhichKey '<Space>'<CR>
vnoremap <silent> <leader> :<c-u>WhichKeyVisual '<Space>'<CR>
