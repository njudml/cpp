" => General
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" Sets how many lines of history VIM has to remember
set history=1000
set pastetoggle=<F9>

" Enable filetype plugins
filetype plugin on
filetype indent on



highlight Pmenu    guibg=darkgrey  guifg=green
highlight PmenuSel guibg=lightgrey guifg=black
" Set to auto read when a file is changed from the outside
set autoread

" With a map leader it's possible to do extra key combinations
" like <leader>w saves the current file
let mapleader = ","
map <silent><leader>ee :!vim ~/.vimrc<cr>

" Fast saving
nmap <leader>w :w!<cr>

" :W sudo saves the file 
" (useful for handling the permission-denied error)
command W w !sudo tee % > /dev/null


"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" => VIM user interface
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" Set 7 lines to the cursor - when moving vertically using j/k
set so=7

" Avoid garbled characters in Chinese language windows OS
let $LANG='en' 
set langmenu=en
source $VIMRUNTIME/delmenu.vim
source $VIMRUNTIME/menu.vim

" Turn on the Wild menu
set wildmenu
" Ignore compiled files
set wildignore=*.o,*~,*.pyc
if has("win16") || has("win32")
    set wildignore+=.git\*,.hg\*,.svn\*
else
    set wildignore+=*/.git/*,*/.hg/*,*/.svn/*,*/.DS_Store
endif

"Always show current position
set ruler
set t_Co=256

" Height of the command bar
set cmdheight=2

" A buffer becomes hidden when it is abandoned
set hid

" Configure backspace so it acts as it should act
set backspace=eol,start,indent
set whichwrap+=<,>,h,l

" Ignore case when searching
set ignorecase

" When searching try to be smart about cases 
set smartcase

" Highlight search results
set hlsearch

" Makes search act like search in modern browsers
set incsearch 

" Don't redraw while executing macros (good performance config)
set lazyredraw 

" For regular expressions turn magic on
set magic

" Show matching brackets when text indicator is over them
set showmatch 
" How many tenths of a second to blink when matching brackets
set mat=2

" No annoying sound on errors
set noerrorbells
set novisualbell
set t_vb=
set tm=500

" Properly disable sound on errors on MacVim
if has("gui_macvim")
    autocmd GUIEnter * set vb t_vb=
endif


" Add a bit extra margin to the left
set foldcolumn=0


"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" => Colors and Fonts
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" Enable syntax highlighting
syntax on 

" Enable 256 colors palette in Gnome Terminal
if $COLORTERM == 'gnome-terminal'
    set t_Co=256
endif

"try
"    colorscheme molokai
"catch
"endtry
"
set background=dark    
"colorscheme VisualStudioDark 
colorscheme badwolf
"colorscheme molokai
let g:molokai_original = 1
let g:rehash256 = 1
" Set extra options when running in GUI mode
if has("gui_running")
    set guioptions-=T
    set guioptions-=e
    set t_Co=256
    set guitablabel=%M\ %t
endif

" Set utf8 as standard encoding and en_US as the standard language
set encoding=utf8

" Use Unix as the standard file type
set ffs=unix,dos,mac


set number
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" => Files, backups and undo
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" Turn backup off, since most stuff is in SVN, git et.c anyway...
set nobackup
set nowb
set noswapfile

set cursorline

"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" => Text, tab and indent related
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" Use spaces instead of tabs
set expandtab

" Be smart when using tabs ;)
set smarttab

" 1 tab == 4 spaces
set shiftwidth=4
set tabstop=4

" Linebreak on 500 characters
set lbr
set tw=500

set ai "Auto indent
set si "Smart indent
set wrap "Wrap lines


""""""""""""""""""""""""""""""
" => Visual mode related
""""""""""""""""""""""""""""""
" Visual mode pressing * or # searches for the current selection
" Super useful! From an idea by Michael Naumann
vnoremap <silent> * :<C-u>call VisualSelection('', '')<CR>/<C-R>=@/<CR><CR>
vnoremap <silent> # :<C-u>call VisualSelection('', '')<CR>?<C-R>=@/<CR><CR>


"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" => Moving around, tabs, windows and buffers
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" Map <Space> to / (search) and Ctrl-<Space> to ? (backwards search)
map <space> /
map <c-space> ?

" Disable highlight when <leader><cr> is pressed
map <silent> <leader><cr> :noh<cr>

" Smart way to move between windows
map <C-j> <C-W>j
map <C-k> <C-W>k
map <C-h> <C-W>h
map <C-l> <C-W>l

set clipboard=unnamed
set mouse=n
set viminfo='1000,f1,<500
" Close the current buffer
map <leader>bd :Bclose<cr>:tabclose<cr>gT

" Close all the buffers
map <leader>ba :bufdo bd<cr>

map <leader>l :bnext<cr>
map <leader>h :bprevious<cr>

" Useful mappings for managing tabs
map <leader>tn :tabnew<cr>
map <leader>to :tabonly<cr>
map <leader>tc :tabclose<cr>
map <leader>tm :tabmove 
"map <leader>t<leader> :tabnext 
noremap <C-RIGHT> <Esc>:tabnext<CR>
noremap <C-LEFT> <Esc>:tabprevious<CR>

" Let 'tl' toggle between this and the last accessed tab
let g:lasttab = 1
nmap <Leader>tl :exe "tabn ".g:lasttab<CR>
au TabLeave * let g:lasttab = tabpagenr()


" Opens a new tab with the current buffer's path
" Super useful when editing files in the same directory
map <leader>te :tabedit <c-r>=expand("%:p:h")<cr>/

" Switch CWD to the directory of the open buffer
map <leader>cd :cd %:p:h<cr>:pwd<cr>

" Specify the behavior when switching between buffers 
try
    set switchbuf=useopen,usetab,newtab
    set stal=2
catch
endtry

" Return to last edit position when opening files (You want this!)
au BufReadPost * if line("'\"") > 1 && line("'\"") <= line("$") | exe "normal! g'\"" | endif


""""""""""""""""""""""""""""""
" => Status line
""""""""""""""""""""""""""""""
" Always show the status line
set laststatus=2

" Format the status line
set statusline=\ %{HasPaste()}%F%m%r%h\ %w\ \ CWD:\ %r%{getcwd()}%h\ \ \ Line:\ %l\ \ Column:\ %c


"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" => Editing mappings
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" Remap VIM 0 to first non-blank character
map 0 ^

" Move a line of text using ALT+[jk] or Command+[jk] on mac
nmap <M-j> mz:m+<cr>`z
nmap <M-k> mz:m-2<cr>`z
vmap <M-j> :m'>+<cr>`<my`>mzgv`yo`z
vmap <M-k> :m'<-2<cr>`>my`<mzgv`yo`z

if has("mac") || has("macunix")
    nmap <D-j> <M-j>
    nmap <D-k> <M-k>
    vmap <D-j> <M-j>
    vmap <D-k> <M-k>
endif

" Delete trailing white space on save, useful for some filetypes ;)
fun! CleanExtraSpaces()
    let save_cursor = getpos(".")
    let old_query = getreg('/')
    silent! %s/\s\+$//e
    call setpos('.', save_cursor)
    call setreg('/', old_query)
endfun

if has("autocmd")
    autocmd BufWritePre *.txt,*.js,*.py,*.wiki,*.sh,*.coffee :call CleanExtraSpaces()
endif


"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" => Spell checking
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" Pressing ,ss will toggle and untoggle spell checking
map <leader>ss :setlocal spell!<cr>

" Shortcuts using <leader>
map <leader>sn ]s
map <leader>sp [s
map <leader>sa zg
map <leader>s? z=


"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" => Misc
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" Remove the Windows ^M - when the encodings gets messed up
noremap <Leader>m mmHmt:%s/<C-V><cr>//ge<cr>'tzt'm

" Quickly open a buffer for scribble
map <leader>q :e ~/buffer<cr>

" Quickly open a markdown buffer for scribble
map <leader>x :e ~/buffer.md<cr>

" Toggle paste mode on and off
map <leader>pp :setlocal paste!<cr>


"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" => Helper functions
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" Returns true if paste mode is enabled
function! HasPaste()
    if &paste
        return 'PASTE MODE  '
    endif
    return ''
endfunction

" Don't close window, when deleting a buffer
command! Bclose call <SID>BufcloseCloseIt()
function! <SID>BufcloseCloseIt()
    let l:currentBufNum = bufnr("%")
    let l:alternateBufNum = bufnr("#")

    if buflisted(l:alternateBufNum)
        buffer #
    else
        bnext
    endif

    if bufnr("%") == l:currentBufNum
        new
    endif

    if buflisted(l:currentBufNum)
        execute("bdelete! ".l:currentBufNum)
    endif
endfunction

function! CmdLine(str)
    exe "menu Foo.Bar :" . a:str
    emenu Foo.Bar
    unmenu Foo
endfunction 

function! VisualSelection(direction, extra_filter) range
    let l:saved_reg = @"
    execute "normal! vgvy"

    let l:pattern = escape(@", "\\/.*'$^~[]")
    let l:pattern = substitute(l:pattern, "\n$", "", "")

    if a:direction == 'gv'
        call CmdLine("Ack '" . l:pattern . "' " )
    elseif a:direction == 'replace'
        call CmdLine("%s" . '/'. l:pattern . '/')
    endif

    let @/ = l:pattern
    let @" = l:saved_reg
endfunction
set autoindent



call plug#begin('~/.vim/plugged')
Plug 'Valloric/YouCompleteMe'
Plug 'honza/vim-snippets'
Plug 'sirver/ultisnips'
Plug 'Yggdroot/indentLine'
Plug 'tpope/vim-surround'
Plug 'ervandew/supertab'
Plug 'easymotion/vim-easymotion'
Plug 'scrooloose/nerdtree'
Plug 'vim-scripts/taglist.vim'
Plug 'majutsushi/tagbar'
Plug 'kien/ctrlp.vim'
Plug 'vim-syntastic/syntastic'
Plug 'Raimondi/delimitMate'
Plug 'octol/vim-cpp-enhanced-highlight'
Plug 'Chiel92/vim-autoformat'
call plug#end()

"supertab
let g:SuperTabDefaultCompletionType="<c-p>"

"autoformat
"let g:formatdef_duoml = '"astyle --style=attach --pad-oper"'
let g:formatdef_duoml = '"clang-format -style=WebKit"'
let g:formatters_cpp = ['duoml']
noremap <F2> :Autoformat<CR>
"
map <silent> <F1> :TlistToggle<CR> `
map <F3> :NERDTreeToggle<CR>
let delimitMate_expand_cr = 1

"easymotion
let g:EasyMotion_smartcase = 1
let g:EasyMotion_startofline = 0 " keep cursor colum when JK motion
map <Leader><leader>h <Plug>(easymotion-linebackward)
map <Leader><Leader>j <Plug>(easymotion-j)
map <Leader><Leader>k <Plug>(easymotion-k)
map <Leader><leader>l <Plug>(easymotion-lineforward)
" 重复上一次操作, 类似repeat插件, 很强大
map <Leader><leader>. <Plug>(easymotion-repeat)


"indentLine 代码缩进线标志线
let g:indentLine_char = '¦' 
let g:indentLine_color_term = 239 
""映射到ctrl+i键 
map <C-i> :IndentLinesToggle<CR>
" YouCompleteMe
let g:ycm_global_ycm_extra_conf = '~/.vim/.ycm_extra_conf.py'
set completeopt-=preview
"" Do not ask when starting vim
let g:ycm_confirm_extra_conf = 0
let g:syntastic_always_populate_loc_list = 1
let g:ycm_server_python_interpreter='/usr/bin/python'
inoremap <expr> <CR>       pumvisible() ? "\<C-y>" : "\<CR>"    "回车即选中当前项  

let g:ycm_min_num_of_chars_for_completion=2
" 从第2个键入字符就开始罗列匹配项  
let g:ycm_cache_omnifunc=0  " 禁止缓存匹配项,每次都重新生成匹配项  
"在注释输入中也能补全  
let g:ycm_complete_in_comments = 1  
"在字符串输入中也能补全  
let g:ycm_complete_in_strings = 1  
"注释和字符串中的文字也会被收入补全  
let g:ycm_collect_identifiers_from_comments_and_strings = 0  
let g:clang_user_options='|| exit 0'  
" YouCompleteMe
"----------------------------"
"Powerline"

"----------------------------"
"--------    CtrlP    -------"
"----------------------------"
let g:ctrlp_map = '\\'
let g:ctrlp_open_multiple_files = 'v'

set wildignore+=*/tmp/*,*.so,*.swp,*.zip
let g:ctrlp_custom_ignore = {
            \ 'dir':  '\v[\/]\.(git)$',
            \ 'file': '\v\.(log|jpg|png|jpeg)$',
            \ }


"----------------------------"

"--------    cpp-highlight    -------"
"----------------------------"
"----------------------------"
"--------    Tagbar    -------"
let g:tarbar_ctags_bin='/usr/bin/ctags'
nmap <silent> <F4> :TagbarToggle<CR>
"----------------------------"
"----------------------------"
"--------    Taglist    -------"
nmap <silent> <F5> :TlistToggle<CR>
"----------------------------"

"UltiSnips
"插入模式下直接通过<C-z>键来触发UltiSnips的代码块补全
let g:UltiSnipsExpandTrigger="<C-z>"
"弹出UltiSnips的可用列表,由于不常用, 所以这里设置成了特殊的<C-i>映射
let g:UltiSnipsListSnippets="<C-i>"
"<C-f>跳转的到下一个代码块可编辑区
let g:UltiSnipsJumpForwardTrigger="<C-f>"
"<C-b>跳转到上一个代码块可编辑区
let g:UltiSnipsJumpBackwardTrigger="<C-b>""

"function! s:onCompleteDone()
"    let abbr = v:completed_item.abbr
"    let startIdx = stridx(abbr,"(")
"    let endIdx = strridx(abbr,")")
"    if endIdx - startIdx > 1
"        let argsStr = strpart(abbr, startIdx+1, endIdx - startIdx -1)
"        let argsList = split(argsStr, ",")
"
"        let argsList = []
"        let arg = ''
"        let countParen = 0
"        for i in range(strlen(argsStr))
"            if argsStr[i] == ',' && countParen == 0
"                call add(argsList, arg)
"                let arg = ''
"            elseif argsStr[i] == '('
"                let countParen += 1
"                let arg = arg . argsStr[i]
"            elseif argsStr[i] == ')'
"                let countParen -= 1
"                let arg = arg . argsStr[i]
"            else
"                let arg = arg . argsStr[i]
"            endif
"        endfor
"        if arg != '' && countParen == 0
"            call add(argsList, arg)
"        endif
"    else
"        let argsList = []
"    endif
"
"    let snippet = '('
"    let c = 1
"    for i in argsList
"        if c > 1
"            let snippet = snippet . ", "
"        endif
"        " strip space
"        let arg = substitute(i, '^\s*\(.\{-}\)\s*$', '\1', '')
"        let snippet = snippet . '${' . c . ":" . arg . '}'
"        let c += 1
"    endfor
"    let snippet = snippet . ')' . "$0"
"    return UltiSnips#Anon(snippet)
"endfunction


set statusline+=%#warningmsg#
set statusline+=%{SyntasticStatuslineFlag()}
set statusline+=%*

let g:syntastic_always_populate_loc_list = 1
let g:syntastic_auto_loc_list = 1
let g:syntastic_check_on_open = 1
let g:syntastic_check_on_wq = 0
function! MyOnCompleteDone()
    if !exists('v:completed_item') || empty(v:completed_item)
        return
    endif

    let complete_str = v:completed_item.word
    if complete_str == ''
        return
    endif
    let abbr = v:completed_item.abbr
    let startIdx = match(abbr,"(")
    let endIdx = match(abbr,")")
    if endIdx - startIdx > 1
        let argsStr = strpart(abbr, startIdx+1, endIdx - startIdx -1)
        let argsList = split(argsStr, ",")
        let snippet = " 
        let c = 1
        for i in argsList
            if c > 1 
                let snippet = snippet. ", "
            endif
            " strip space
            let arg = substitute(i, '^\s*\(.\{-}\)\s*$', '\1', '') 
            let snippet = snippet . '${'.c.":".arg.'}'
            let c += 1
        endfor
        let snippet = snippet . ")$0"
        call UltiSnips#Anon(snippet)
    endif
endfunction
autocmd CompleteDone *.go  call MyOnCompleteDone()
