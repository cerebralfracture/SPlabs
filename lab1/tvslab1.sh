#!/bin/bash
echo "программа блокировки пользователя"
echo "блокировка и разблокировка пользователя"
echo "Trofimova Varvara"

echo "Enter name user"
read username
getent passwd "$username"

while true
do

echo "1-lock user"
echo "2-Unlock user"
echo "3-Exit"

read bu
case $bu in
1)
passwd -l $username;;
2)
passwd -u $username;;
3)
exit 0;;
*)
echo "This is an error" >&2
echo "This is normal output"
esac

done
