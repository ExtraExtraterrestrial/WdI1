type=$1
msg=$2
> data/app.log  # clears the file

msg="Log nr"

for i in $(seq 1 $(shuf -i 10-20 -n 1));
do
    #shuf generates random numbers
    if [[ "$(shuf -i 1-3 -n 1)" -eq 1 ]]; then
        type="INFO"
    elif [[ "$(shuf -i 1-2 -n 1)" -eq 1 ]]; then
        type="WARN"
    else
        type="ERROR"
    fi

    # echo -e interprets escaped characters
    echo -e "[$(date +%d-%m-%Y\ %H:%M:%S)] \t $type \t $msg $i" >> data/app.log
done
