#!/bin/bash

# Roll-No: 33231
# Name: Abhijeet Ingle
# Batch: K-10

# This section is used to store color codes which will be displayed during output

RED="\e[31m"
MAGNETA="\e[35m"
GREEN="\e[32m"
ENDCOLOR="\e[0m"
CYAN="\e[36m"
YELLOW="\e[33m"
BLUE="\e[34m"


#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~CREATE FUNCTION~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

CREATE() 
{ 
	echo -e "${CYAN}Enter Name of the file:${ENDCOLOR}"
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
		 
		echo -e "CASEID|COMPLAINER|ACCUSED|REASON|DATE"  >> $file_name.txt

	fi
}


#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ADD FUNCTION~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

ADD() 
{ 
	if [ -z $file_name ]  # checks if file length is zero
	then
		echo -e "${MAGNETA}Please create or select file first before adding contents!!!!!${ENDCOLOR}"
	
	else  	
		echo -e "Enter Case ID:"
		read CaseID
		
		echo -e "Name of Complainer:"
		read Complainer
		
		echo -e "Name of Accused:"
		read Accused
		
		echo -e "Reason:"
		read Reason
		
		echo -e "DATE:(DD:MM:YYYY):"
		read -p "ENTER DAY(DD):" DAY
		read -p "ENTER MONTH(MM):" MONTH
		read -p "ENTER YEAR(YYYY):" YEAR
		
		# VALIDATING DATE
		
		if (($DAY < 1 || $DAY > 31));
		then
			echo -e "${YELLOW}ERROR:${ENDCOLOR}${MAGNETA}DAY should be between 1-31${ENDCOLOR}"
			return
		fi
		
		if (($MONTH < 1 || $MONTH > 12));
		then
			echo -e "${YELLOW}ERROR:${ENDCOLOR}${MAGNETA}MONTH should be between 1-12${ENDCOLOR}"
			return
		fi	
		
		if (($YEAR < 1600 || $YEAR > 2022));
		then
			echo -e "${YELLOW}ERROR:${ENDCOLOR}${MAGNETA}DAY should be between 1600-2022${ENDCOLOR}"
			return
		fi
		
		
		DATE="$DAY:$MONTH:$YEAR"
		
		echo -e "$CaseID|$Complainer|$Accused|$Reason|$DATE"   >> $file_name.txt
	fi
}

#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~DISPLAY FUNCTION~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

DISPLAY()
{
	echo -e "${GREEN}~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~${ENDCOLOR}"
	cat $file_name.txt | column -t -s "|"
	echo -e "${GREEN}~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~${ENDCOLOR}"
}


#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~DELETE FUNCTION~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

DELETE() 
{ 
	echo -e "${MAGNETA}Enter the CaseID which is to be deleted:${ENDCOLOR}"
	read Delete_CaseID
	
	flag=`cat $file_name.txt | grep $Delete_CaseID | wc -l`
	
	if [ $flag -eq 1 ] #checking valid CaseID
	then 
		deleted_item=`cat $file_name.txt | grep $Delete_CaseID`
		sed -i "/^$Delete_CaseID/d" $file_name.txt
		    # Deleting CaseID
		
		echo -e "${MAGNETA}Record Deleted Successfuly\n Record: $deleted_item ${ENDCOLOR}"
	
	else
		echo -e "${YELLOW}Entered CaseID doesn't exist!!!{ENDCOLOR}{ENDCOLOR}"
	fi
}


#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~MODIFY FUNCTION~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

MODIFY()
{
	echo -e "${MAGNETA}Enter the CaseID to modify the Case Entry:${ENDCOLOR}"
	read modify_CaseID
	check_flag=`cat $file_name.txt | grep $modify_CaseID | wc -l`
	if [ $check_flag -eq 0 ]
	then
		echo -e "${YELLOW}Entered CaseID doesn't exist, Check Again!!!${ENDCOLOR}"
	else
		original_line=`cat $file_name.txt | grep $modify_CaseID`
		
		echo -e "${MAGNETA}Enter the following values to modify the file:${ENDCOLOR}"
		
		read -p "Enter Name of Complainer:" New_Complainer
		read -p "Enter Name of Accused:" New_Accused 
		read -p "Enter Reason:" New_Reason 
		echo -e "DATE:(DD:MM:YYYY):"
		read -p "ENTER DAY(DD):" DAY
		read -p "ENTER MONTH(MM):" MONTH
		read -p "ENTER YEAR(YYYY):" YEAR
		
		
		# VALIDATING DATE
		
		if (($DAY < 1 || $DAY > 31));
		then
			echo -e "${YELLOW}ERROR:${ENDCOLOR}${MAGNETA}DAY should be between 1-31${ENDCOLOR}"
			return
		fi
		
		if (($MONTH < 1 || $MONTH > 12));
		then
			echo -e "${YELLOW}ERROR:${ENDCOLOR}${MAGNETA}MONTH should be between 1-12${ENDCOLOR}"
			return
		fi	
		
		if (($YEAR < 1600 ||5 $YEAR > 2022));
		then
			echo -e "${YELLOW}ERROR:${ENDCOLOR}${MAGNETA}DAY should be between 1600-2022${ENDCOLOR}"
			return
		fi
		
		
		DATE="$DAY:$MONTH:$YEAR"
		
		
		
		
		new_line="$modify_CaseID|$New_Complainer|$New_Accused|$New_Reason|$New_Date"
		
		sed -i "s/$original_line/$new_line/" $file_name.txt
		
		echo "Changes done!"
	fi	
}


#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~MAIN CODE~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


# MENU
echo -e "${GREEN}CRIME DATABASE ${ENDCOLOR}"
echo -e "${CYAN}Select an Operation (Enter q to exit)\nEnter : \n  c to Create New file or Select Existing File\n  a to ADD Entries to File \n  d to Display File \n  de to Delete Case Content\n  m to Modify File \n  q to Exit ${ENDCOLOR}"
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
	echo -e "${CYAN}Select an Operation (Enter q to exit)\nEnter : \n  c to Create New file or Select Existing File\n  a to ADD Entries to File \n  d to Display File \n  de to Delete Case Content\n  m to Modify File \n  q to Exit${ENDCOLOR}"
	read Operation

done	
	
# Roll-No: 33231
# Name: Abhijeet Ingle
# Batch: K-10

#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
