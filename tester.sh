#! /bin/bash

RED='\033[0;31m'
GREEN='\033[0;32m'
NC='\033[0m'

EXECFT=ft_containers
EXECSTD=std_containers

STACKFT=logs/output/ft_stack.log
STACKSTD=logs/output/std_stack.log
VECTORFT=logs/output/ft_vector.log
VECTORSTD=logs/output/std_vector.log
MAPFT=logs/output/ft_map.log
MAPSTD=logs/output/std_map.log
SETFT=logs/output/ft_set.log
SETSTD=logs/output/std_set.log

compare_outputs() {
	if [[ -f "$1" && -f "$2" ]]; then
	if diff $1 $2 &> /dev/null; then
		echo -e "${GREEN}OK${NC}"
	else
		echo -e "${RED}KO${NC}"
	fi
else
	echo -e "${RED}FAILED${NC}"
fi
}

make

if [[ -f "$EXECFT" && -f "$EXECSTD" ]]; then
	echo -e "\nexecuting $EXECFT"
	./$EXECFT
	echo -e "\nexecuting $EXECSTD"
	./$EXECSTD
else
	echo "couldn't find ./$EXECFT and/or ./$EXECSTD"
	exit 1
fi

echo -ne "\nSTACK:\t"

compare_outputs $STACKFT $STACKSTD

echo -ne "VECTOR:\t"

compare_outputs $VECTORFT $VECTORSTD

echo -ne "MAP:\t"

compare_outputs $MAPFT $MAPSTD

echo -ne "SET:\t"

compare_outputs $SETFT $SETSTD
