<h1  align="center">Assignment 1</h1>

## Code

```bash
#!/bin/bash

# Provide permissions using following command
# chmod u+x 'Assignment 1.sh'
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~CREATE FUNCTION~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

CREATE()
{
	echo -e "Enter Name of the file:"
	read entered_file

	# Checking if file already exists
	search=`ls | grep $entered_file | wc -l`

	if (( $search > 0 ))
	then
		file_name=$entered_file
		echo -e "${MAGNETA}Selected file named: $file_name ${ENDCOLOR}"
	else
		file_name=$entered_file
		touch $file_name.txt
		echo -e "${MAGNETA}Created file named: $file_name ${ENDCOLOR}"

		echo -e "ID|NAME|ADDRESS|PHONE_NO"  >> $file_name.txt

	fi
}


#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ADD FUNCTION~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

ADD()
{
	if [ -z $file_name ]  # checks if file length is zero
	then
		echo -e "${MAGNETA}Please create or select file first before adding contents!!!!!${ENDCOLOR}"

	else
		echo -e "Enter ID:"
		read ID

		echo -e "Enter Name:"
		read Name

		echo -e "Enter Address:"
		read Address

		echo -e "Enter Phone No:"
		read Phone

		echo -e "$ID|$Name|$Address|$Phone"   >> $file_name.txt
	fi
}

#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~DISPLAY FUNCTION~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

DISPLAY()
{
	echo -e "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"
	cat $file_name.txt | column -t -s "|"
	echo -e "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"
}


#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~DELETE FUNCTION~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

DELETE()
{
	echo -e "Enter the ID which is to be deleted:"
	read Delete_ID

	flag=`cat $file_name.txt | grep $Delete_ID | wc -l`

	if [ $flag -eq 1 ] #checking valid ID
	then
		deleted_item=`cat $file_name.txt | grep $Delete_ID`
		sed -i "/^$Delete_ID/d" $file_name.txt
		    # Deleting ID

		echo -e "Record Deleted Successfuly\n Record: $deleted_item"

	else
		echo -e "Entered ID doesn't exist!!!"
	fi
}


#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~MODIFY FUNCTION~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

MODIFY()
{
	echo -e "Enter the ID to modify the Entry: "
	read modify_ID
	check_flag=`cat $file_name.txt | grep $modify_ID | wc -l`
	if [ $check_flag -eq 0 ]
	then
		echo -e "Entered ID doesn't exist, Check Again!!!"
	else
		original_line=`cat $file_name.txt | grep $modify_ID`

		echo -e "Enter the following values to modify the file: "

		read -p "Enter Name: " New_Name
		read -p "Enter Address: " New_Address
		read -p "Enter Phone No: " New_Phone

		new_line="$modify_ID|$New_Name|$New_Address|$New_Phone"

		sed -i "s/$original_line/$new_line/" $file_name.txt

		echo "Changes done!"
	fi
}


#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~MAIN CODE~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


# MENU
echo -e "ADDRESS BOOK"
echo -e "Select an Operation (Enter q to exit)\nEnter : \n  c to Create New file or Select Existing File\n  a to ADD Entries to File \n  d to Display File \n  de to Delete Content\n  m to Modify File \n  q to Exit "
read Operation


while [ $Operation != q ]
do



	case $Operation in  # CASE FOR VARIOUS OPTIONS ; FUNCTIONS CALL FOR RESPECTIVE OPTIONS

		c)
		CREATE
		;;

		a)
		ADD
		;;

		d)
		DISPLAY
		;;

		de)
		DELETE
		;;

		m)
		MODIFY
		;;


		*)   # ERROR MESSAGE FOR IRRELEVANT ENTRIES
		echo "Invalid Entry!!!"
		;;


	esac
	echo -e "Select an Operation (Enter q to exit)\nEnter : \n  c to Create New file or Select Existing File\n  a to Add Entries to File \n  d to Display File \n  de to Delete Content\n  m to Modify File \n  q to Exit"
	read Operation

done
```

---

## Output

```text
abhishek-jadhav@abhishek-jadhav-ubuntu:~/Codes/OS Assignments/33232$ ./'Assignment_1.sh'
ADDRESS BOOK
Select an Operation (Enter q to exit)
Enter :
  c to Create New file or Select Existing File
  a to ADD Entries to File
  d to Display File
  de to Delete Content
  m to Modify File
  q to Exit
c
Enter Name of the file:
Address_Book
Created file named: Address_Book
Select an Operation (Enter q to exit)
Enter :
  c to Create New file or Select Existing File
  a to Add Entries to File
  d to Display File
  de to Delete Content
  m to Modify File
  q to Exit
a
Enter ID:
33232
Enter Name:
Abhishek Jadhav
Enter Address:
Pune, Maharashtra
Enter Phone No:
7030405299
Select an Operation (Enter q to exit)
Enter :
  c to Create New file or Select Existing File
  a to Add Entries to File
  d to Display File
  de to Delete Content
  m to Modify File
  q to Exit
d
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
ID     NAME             ADDRESS            PHONE_NO
33232  Abhishek Jadhav  Pune, Maharashtra  7030405299
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Select an Operation (Enter q to exit)
Enter :
  c to Create New file or Select Existing File
  a to Add Entries to File
  d to Display File
  de to Delete Content
  m to Modify File
  q to Exit
a
Enter ID:
33232
Enter Name:
Abhishek Jadhav
Enter Address:
Nashik, Maharashtra
Enter Phone No:
7030405299
Select an Operation (Enter q to exit)
Enter :
  c to Create New file or Select Existing File
  a to Add Entries to File
  d to Display File
  de to Delete Content
  m to Modify File
  q to Exit
d
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
ID     NAME             ADDRESS              PHONE_NO
33232  Abhishek Jadhav  Pune, Maharashtra    7030405299
33232  Abhishek Jadhav  Nashik, Maharashtra  7030405299
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Select an Operation (Enter q to exit)
Enter :
  c to Create New file or Select Existing File
  a to Add Entries to File
  d to Display File
  de to Delete Content
  m to Modify File
  q to Exit
m
Enter the ID to modify the Entry:
33232
Enter the following values to modify the file:
Enter Name: AbhishekJadhav2002
Enter Address: Pune-411046
Enter Phone No: 7030405299
sed: -e expression #1, char 52: unterminated `s' command
Changes done!
Select an Operation (Enter q to exit)
Enter :
  c to Create New file or Select Existing File
  a to Add Entries to File
  d to Display File
  de to Delete Content
  m to Modify File
  q to Exit
d
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
ID     NAME             ADDRESS              PHONE_NO
33232  Abhishek Jadhav  Pune, Maharashtra    7030405299
33232  Abhishek Jadhav  Nashik, Maharashtra  7030405299
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Select an Operation (Enter q to exit)
Enter :
  c to Create New file or Select Existing File
  a to Add Entries to File
  d to Display File
  de to Delete Content
  m to Modify File
  q to Exit
de
Enter the ID which is to be deleted:
33232
Entered ID doesn't exist!!!
Select an Operation (Enter q to exit)
Enter :
  c to Create New file or Select Existing File
  a to Add Entries to File
  d to Display File
  de to Delete Content
  m to Modify File
  q to Exit
q
abhishek-jadhav@abhishek-jadhav-ubuntu:~/Codes/OS Assignments/33232$
```
