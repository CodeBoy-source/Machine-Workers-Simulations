# Get Script Directory to later find the bin path
SCRIPT_DIR="$( cd -- "$( dirname -- "${BASH_SOURCE[0]:-$0}"; )" &> /dev/null && pwd 2> /dev/null; )";

declare -a func_types=(0 1 2)

sz_func=${#func_types[@]}
for (( j = 0; j < sz_func ; j++ )); do
    $SCRIPT_DIR/../bin/maquinas1trabajador 10000 ${func_types[j]} 1
done
