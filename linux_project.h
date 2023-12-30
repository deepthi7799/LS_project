#!/bin/bash
echo "1.sign up
2.sign in
3.Exit"
read -p "Enter the option:" option
case $option in
        1)
                read -p "User Name:" user_name
                user_array=(`cat user_name.csv`)
                count=0
                for i in ${user_array[*]}
                do
                        if [ $user_name = $i ]
                        then
                                count=$((count+1))
                        fi
                done
                if [ $count -ne 0 ]
                then
                        echo "The name Entered is already exists.Please enter the other user_name."
                else
                        read -p "Enter password:" pass_word
                        read -p "Enter confirm password:" con_passwd
                        if [ $pass_word = $con_passwd ]
                        then
                                echo $user_name >> user_name.csv
                                echo $pass_word >> user_password.csv
                                echo "SIGN UP SUCCESSFULLY"
                                echo "sign in"
                        else
                                echo "please Enter correct password"
                        fi
                fi
        ;;
        2)
                read -p "Enter Username:" user_name
                user_array=(`cat user_name.csv`)
                user_password=(`cat user_password.csv`)
                count=0
                for i in ${user_array[*]}
                do
                        if [ $i = $user_name ]
                        then
                                count=$((count+1))
                        fi
                done
                if [ $count -ne 0 ]
                then
                        count1=0
                        read -p "Enter password:" pass_wd
                        for j in ${user_password[*]}
                        do
                                if [ $j = $pass_wd ]
                                then
                                        count1=$((count1+1))
                                fi
                        done
                        if [ $count1 -ne 0 ]
                        then
                                echo "SIGN IN SUCCESSFULLY"
                                echo "1.Take the Test
2.Exit"
                                read -p "Enter option:" opt
                                if [ $opt -eq 1 ]
                                then
                                        echo "---------------------------TEST-------------------"
                                        len=`cat question.csv | wc -l`
                                        for i in `seq 5 5 $len`
                                        do
                                                head -$i question.csv | tail -5
                                                for k in `seq 5 -1 1`
                                                do
                                                        echo -en "\rEnter ans:$k:"
                                                        read -t 1 opt11
                                                done
                                                echo "ANSWER:"$opt11
                                                if [ -z $opt11 ]
                                                then
                                                        opt1="xxx"
                                                else
                                                        opt1=$opt11
                                                fi
                                                echo $opt1 >> user_ans.csv
                                        done
                                        user_ans_array=(`cat user_ans.csv`)
                                        correct_ans_array=(`cat correct_ans.csv`)
                                        arr_len=${#correct_ans_array[*]}
                                        echo "-------------CORRECT ANSWERS--------------"
                                        marks=0
                                        line_len=5
                                        echo
                                        for i in `seq 0 $(($arr_len-1))`
                                        do
                                        head -$line_len question.csv | tail -5
                                        echo
                                        echo User ans:${user_ans_array[i]}     Correct ans:${correct_ans_array[i]}
                                        echo
                                        if [ ${user_ans_array[i]} = ${correct_ans_array[i]} ]
                                        then
                                                marks=$((marks+1))
                                        fi
                                                line_len=$((line_len+5))
                                        done
                                        echo "---------TEST COMPLETED-----------------"
                                        echo "TOTAL MARKS: " $marks
                                else
                                        echo "EXIT SUCCESSFULLY"
                                fi
                        else

                                echo "enter correct password"
                        fi
                else
                        echo "Enter correct user name/SIGNUP FIRST"
                fi
        ;;
        3)
                echo "EXIT SUCCESSFULLY"
        ;;
esac