# !/bin/bash

# Check if two arguments are provided
if [ $# -ne 2 ]; then
  echo "Usage: $0 <start_number> <end_number>"
  exit 1
fi

start=$1
end=$2

echo "Odd numbers between $start and $end:"
for (( i=$start; i<=$end; i++ )); do
  if (( i % 2 != 0 )); then
    echo -n "$i "
  fi
done
echo ""

echo "Even numbers between $start and $end:"
for (( i=$start; i<=$end; i++ )); do
  if (( i % 2 == 0 )); then
    echo -n "$i "
  fi
done
echo ""

echo "Prime numbers between $start and $end:"
for (( i=$start; i<=$end; i++ )); do
  if (( i < 2 )); then
    continue
  fi
  is_prime=1
  for (( j=2; j*j<=i; j++ )); do
    if (( i % j == 0 )); then
      is_prime=0
      break
    fi
  done
  if (( is_prime == 1 )); then
    echo -n "$i "
  fi
done
echo ""
