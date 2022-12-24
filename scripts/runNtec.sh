# Get Script Directory to later find the bin path
SCRIPT_DIR="$( cd -- "$( dirname -- "${BASH_SOURCE[0]:-$0}"; )" &> /dev/null && pwd 2> /dev/null; )";

declare -a metrics=(0 1)
declare -a simulaciones=(1 5)

sz_metrics=${#metrics[@]}
sz_sim=${#simulaciones[@]}
for (( j = 0; j < sz_metrics; j++ )); do
    for (( i = 0; i < sz_sim; i++ )); do
        $SCRIPT_DIR/../bin/ntec ${simulaciones[i]} ${metrics[j]} 1
    done
done
