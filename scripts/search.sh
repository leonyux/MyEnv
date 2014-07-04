echo Search: $1
find ./ -regex ".*\.py" | xargs grep -n $1
