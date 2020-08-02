# name in folder (github)
# ± if in github repo, or ≥ if otherwise Time in 24-hour format is on right.
function collapse_pwd {
    echo $(pwd | sed -e "s,^$HOME,~,")
}
function prompt_char {
    echo -n "%{$bg[white]%}%{$fg[red]%}"
    git branch >/dev/null 2>/dev/null && echo "±%{$reset_color%}" && return
    echo "≥%{$reset_color%}"
}

#local ret_status="%(?:%{$fg_bold[green]%}➜ :%{$fg_bold[red]%}➜ )"
#PROMPT='${ret_status} ${user}@${ip} ${dir} $(git_prompt_info)'

#RIXIUS_PRE="%{$bg[white]%}%{$fg[red]%}"
RIXIUS_PRE="%{$fg[cyan]%}"
RET_STATUS="%(?:%{$fg_bold[green]%}➜ :%{$fg_bold[red]%}➜ )"

function get_ip {
    echo -n "%{$fg[yellow]%}$(hostname -i)"
    echo "%{$reset_color%}"
}

PROMPT='${RET_STATUS} %{$RIXIUS_PRE%}%n%{$reset_color%}@$(get_ip) %{$fg_bold[blue]%}$(collapse_pwd)%{$reset_color%} $(git_prompt_info)'
RPROMPT='%{$RIXIUS_PRE%}%T%{$reset_color%}'

#ZSH_THEME_GIT_PROMPT_PREFIX=" %{$fg[magenta]%}"
#ZSH_THEME_GIT_PROMPT_SUFFIX="%{$reset_color%}"
#ZSH_THEME_GIT_PROMPT_DIRTY=" %{$RIXIUS_PRE%}✗%{$reset_color%}"
#ZSH_THEME_GIT_PROMPT_CLEAN=" %{$RIXIUS_PRE%}√%{$reset_color%}"

ZSH_THEME_GIT_PROMPT_PREFIX="%{$fg_bold[green]%}git:(%{$fg[red]%}"
ZSH_THEME_GIT_PROMPT_SUFFIX="%{$reset_color%} "
ZSH_THEME_GIT_PROMPT_DIRTY="%{$fg[green]%}) %{$fg[yellow]%}✗"
ZSH_THEME_GIT_PROMPT_CLEAN="%{$fg[green]%}) %{$fg[yellow]%}√"
