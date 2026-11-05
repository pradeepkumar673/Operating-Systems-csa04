yes ABCDEFGHIJKLMNOPQRSTUVWXYZ | tr -d '\n' | head -c 10000 > records.dat
yes ABCDEFGHIJKLMNOPQRSTUVWXYZ | tr -d '\n' | head -c 16777216 > big.dat
