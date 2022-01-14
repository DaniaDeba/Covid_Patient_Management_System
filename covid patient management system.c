#include<stdio.h>

#include<stdlib.h>

#include<conio.h>

#include<string.h>

void addrecord();

void viewrecord();

void editrecord();

void searchrecord();

void deleterecord();

void login();

struct record

{char id[10];

    char name[30];

    char age[6];

    char gender[10];

    char weight[20];

    char height[20];

    char health[20];

    char infected[20];

    char date[40];

    char symptoms[20];

    char isolated [20];

	char doctor[20];

    char positive[50];

    char state[20];

    char district[20];

    char emergencyc[20];

    char emergencyr[20];

    char datearr[20];


} a;

int main()


{
	login();

    int ch;
    printf("\n\n\t    ====================================\n");
    printf("\t   - COVID-19 PATIENT'S RECORD MANAGEMENT SYSTEM-\n");
    printf("\t    ====================================");

    while(1)
    {

        printf("\n\n\t\t::MAIN MENU::");
        printf("\n\n\t\tADD NEW PATIENT RECORD\t[ENTER-1]");
        printf("\n\t\tSEARCH RECORD\t[ENTER-2]");
        printf("\n\t\tMODIFY RECORD\t[ENTER-3]");
        printf("\n\t\tLIST RECORD\t[ENTER-4]");
		printf("\n\t\tDELETE RECORD\t[ENTER-5]");
        printf("\n\t\tEXIT\t\t[ENTER-6]");
        printf("\n\n\t=> ENTER YOUR CHOICE:");
        scanf("%d",&ch);

        switch(ch)
        {

        case 1:
            addrecord();
            break;

        case 2:
            searchrecord();
            break;

        case 3:
            editrecord();
            break;

        case 4:
            viewrecord();
            break;

        case 5:
            deleterecord();
            break;

        case 6:
        	system("cls");
            printf(" ");
            getch();
            exit(0);

        default:
            printf("\nYOU ENTERED WRONG CHOICE.");
            printf("\nPRESS ANY KEY TO TRY AGAIN");
            getch();
            break;

        }

        system("cls");

    }
    return 0;

}



/**************** ADDING FUNCTION************************/

void addrecord( )

{
    system("cls");
    FILE *fp ;
    char another = 'Y' ,id[10];
    char filename[30];
    int choice;

    printf("\n\n\t\t====================================\n");
    printf("\t\t\t  - ADD RECORDS -");
    printf("\n\t\t====================================\n");
    printf("\n\n\tENTER FIRST NAME OF THE PATIENT (To Check whether record exists or not): ");
    fflush(stdin);
    gets(filename);

    fp = fopen ("filename", "ab+" ) ;

    if ( fp == NULL )
    {

        fp=fopen("filename","wb+");
        if(fp==NULL)
        {

            printf("\nSYSTEM ERROR...");
            printf("\nPRESS ANY KEY TO EXIT");
            getch();
            return ;

        }
    }

    while ( another == 'Y'|| another=='y' )

    {
        choice=0;
        fflush(stdin);

		printf ( "\tENTER PATIENT CODE(To check whether it matches or not): ");
        scanf("%s",id);

		rewind(fp);

        while(fread(&a,sizeof(a),1,fp)==1)
        {
            if(strcmp(a.id,id)==0)
            {

                printf("\n\tTHE RECORD ALREADY EXISTS.\n");
                choice=1;

            }

        }

        if(choice==0)
        {

            strcpy(a.id,id);

            printf("\n\tENTER NAME OF PATIENT: ");
            fflush(stdin);
            gets(a.name);

			printf("\tENTER SEX: ");
            gets(a.gender);
            fflush(stdin);

            printf("\tENTER AGE: ");
            gets(a.age);
            fflush(stdin);

            printf("\tENTER WEIGHT: ");
            gets(a.weight);
            fflush(stdin);

            printf("\tENTER HEIGHT(FT): ");
            gets(a.height);
 			fflush(stdin);

            printf("\tENTER. IF ANY PREVIOUS HEALTH CONTDITION: ");
            gets(a.health);
            fflush(stdin);

            printf("\tENTER. IF INTERACTED WITH INFECTED: ");
            gets(a.infected);
            fflush(stdin);

            printf("\tENTER DATE FELT INFECTED: ");
            gets(a.date);
            fflush(stdin);


			printf("\tENTER. FELT ANY KIND OF SYMPTOMS : ");
            gets(a.symptoms);
            fflush(stdin);


            printf("\tENTER ISOLATED FROM OTHERS ?: ");
            gets(a.isolated);
            fflush(stdin);

            printf("\t CONSULTED ANY DOCTOR ? : ");
            gets(a.doctor);
            fflush(stdin);

            printf("\tENTER. DATE FOUND COVID-19 POSITIVE: ");
            gets(a.positive);
            fflush(stdin);

            printf("\tENTER. STATE OF THE PATIENT: ");
            gets(a.state);
            fflush(stdin);

            printf("\tENTER. DISTRICT OF THE PATIENT: ");
            gets(a. district);
            fflush(stdin);

            printf("\tENTER. EMERGENCY CONTACT NUMBER: ");
            gets(a.emergencyc);
            fflush(stdin);

            printf("\tENTER. RELATIONSHIP OF EMERGENCY CONTACT WITH PATIENT: ");
            gets(a.emergencyr);
            fflush(stdin);

            printf("\tENTER. DATE OF HOSPITALISATON: ");
            gets(a.datearr);

            fwrite ( &a, sizeof ( a ), 1, fp ) ;
            printf("\nYOUR RECORD IS ADDED...\n");

        }

        printf ( "\n\tADD ANOTHER RECORD...(Y/N) \t" ) ;
        fflush ( stdin ) ;
        another = getch( ) ;

    }

    fclose ( fp ) ;
    printf("\n\n\tPRESS ANY KEY TO EXIT...");
    getch();

}

/**************** SEARCHING FUNCTION************************/

void searchrecord( )

{
	system("cls");
    FILE *fp ;
	char id[16],choice,filename[14];
    int ch;

    printf("\n\n\t\t====================================\n");
    printf("\t\t\t- SEARCH RECORDS -");
    printf("\n\t\t====================================\n\n");

    do
	{

		printf("\n\tENTER THE PATIENT NAME TO BE SEARCHED:");
        fflush(stdin);
        gets(filename);

        fp = fopen ( "filename", "rb" ) ;




    		printf("\nENTER PATIENT CODE:");
            gets(id);
            system("cls");
            printf("\nTHE WHOLE RECORD IS:");

            while ( fread ( &a, sizeof ( a ), 1, fp ) == 1 )


          if(strcmpi(a.id,id)==0)
               { printf("\n");
                printf("\nPATIENT'S NAME IS: %s",a.name);
                printf("\nPATIENT's GENDER IS: %s",a.gender);
                printf("\nPATIENT's AGE IS: %s",a.age);
                printf("\nPATIENT's WEIGHT IS: %s",a.weight);
                printf("\nPATIENT's HEIGHT IS: %s",a.height);
                printf("\nPATIENT's PREVIOUS HEALTH CONTDITION : %s",a.health);
				printf("\nPATIENT INTERACTED WITH INFECTED : %s",a.infected);
                printf("\nPATIENT FELT INFECTED : %s",a.date);
                printf("\nPATIENT'S SYMPTOMS: %s",a.symptoms);
                printf("\nISOLATED FROM OTHERS ?: %s",a.isolated);
                printf("\nCONSULTED A DOCTOR ? : %s",a.doctor);
                printf("\nDATE FOUND COVID-19 POSITIVE: %s",a.positive);
                printf("\nSTATE OF THE PATIENT : %s",a.state);
                printf("\nDISTRICT OF THE PATIENT: %s",a.district);
                printf("\nPATIENT's EMERGENCY CONTACT NUMBER : %s",a.emergencyc);
                printf("\nRELATIONSHIP OF EMERGENCY CONTACT WITH PATIENT: %s",a.emergencyr);
                printf("\nHOSPITALISATION DATE: %s",a.datearr);
                printf("\n");
            }




        printf("\n\nWOULD YOU LIKE TO CONTINUE VIEWING...(Y/N):");
        fflush(stdin);

        scanf("%c",&choice);

    }
    while(choice=='Y'||choice=='y');

    fclose ( fp) ;
	getch();
    return ;
getch();
}


//*********************************************************
/**************** EDITING FUNCTION************************/
//*********************************************************

void editrecord()

{

    system("cls");
    FILE *fp ;
    char id[10],choice,filename[14];
    int num,count=0;

    printf("\n\n\t\t====================================\n");
    printf("\t\t\t- MODIFY RECORDS -");
    printf("\n\t\t====================================\n\n");

    do
    {

        printf("\n\tENTER THE PATIENT's' NAME TO BE EDITED:");
        fflush(stdin);
        gets(filename);

        printf("\n\tENTER ID:");
    	gets(id);
        fp = fopen ( "filename", "rb+" ) ;

        if ( fp == NULL )
        {

            printf( "\nRECORD DOES NOT EXIST:" ) ;
            printf("\nPRESS ANY KEY TO GO BACK");
            getch();
            return;

        }

        while ( fread ( &a, sizeof ( a ), 1, fp ) == 1 )
        {

            if(strcmp(a.id,id)==0)
            {

                printf("\nYOUR OLD RECORD WAS AS:");
                printf("\nPATIENT's NAME: %s",a.name);
                printf("\nPATIENT's SEX: %s",a.gender);
                printf("\nPATIENT's AGE: %s",a.age);
                printf("\nPATIENT's WEIGHT: %s",a.weight);
                printf("\nPATIENT's HEIGHT: %s",a.height);
                printf("\nPATIENT's  PREVIOUS HEALTH CONTDITION: %s",a.health);
				printf("\nPATIENT INTERACTED WITH INFECTED: %s",a.infected);
                printf("\nPATIENT  FELT INFECTED: %s",a.date);
                printf("\nPATIENT'S SYMPTOMS: %s",a.symptoms);
                printf("\nISOLATED FROM OTHERS ? : %s",a.isolated);
                printf("\nCONSULTED A DOCTOR ? : %s",a.doctor);
                printf("\nDATE FOUND COVID-19 POSITIVE: %s",a.positive);
                printf("\nSTATE OF THE PATIENT: %s",a.state);
                printf("\nDISTRICT OF THE PATIENT: %s",a.district);
                printf("\nPATIENT's EMERGENCY CONTACT NUMBER: %s",a.emergencyc);
                printf("\nRELATIONSHIP OF EMERGENCY CONTACT WITH PATIENT: %s",a.emergencyr);
                printf("\nHOSPITALISATION DATE: %s",a.datearr);



                printf("\n\n\t\tWHAT WOULD YOU LIKE TO EDIT..");



                printf("\n1.NAME.");
                printf("\n2.SEX.");
                printf("\n3.AGE.");
                printf("\n4.WEIGHT.");
                printf("\n5.HEIGHT.");
                printf("\n6.PREVIOUS HEALTH CONTDITION.");
                printf("\n7.INTERACTED WITH INFECTED.");
                printf("\n8.FELT INFECTED.");
                printf("\n9.SYMPTOMS.");
                printf("\n10.ISOLATED FROM OTHERS ?.");
                printf("\n11.CONSULTED A DOCTOR ? .");
                printf("\n12. FOUND COVID-19 POSITIVE.");
                printf("\n13.STATE OF THE PATIENT.");
                printf("\n14.DISTRICT OF THE PATIENT.");
                printf("\n15.PATIENT's EMERGENCY CONTACT NUMBER.");
                printf("\n16.RELATIONSHIP OF EMERGENCY CONTACT WITH PATIENT.");
                printf("\n17.HOSPITALISATION DATE.");
                printf("\n18.WHOLE RECORD.");
                printf("\n19.GO BACK TO MAIN MENU.");

                do
                {

                    printf("\n\tENTER YOUR CHOICE:");
                    fflush(stdin);
                    scanf("%d",&num);
                    fflush(stdin);

                    switch(num)
                    {

                    case 1:
                        printf("\nENTER THE NEW DATA:");
                        printf("\nNAME:");
                        gets(a.name);
                        break;

                    case 2:
                        printf("\nENTER THE NEW DATA:");
                        printf("\nSEX:");
                        gets(a.gender);
                        break;

                    case 3:
                        printf("\nENTER THE NEW DATA:");
                        printf("\nAGE:");
                        gets(a.age);
                        break;

                    case 4:
                        printf("\nENTER THE NEW DATA:");
                        printf("\nWEIGHT:");
                        gets(a.weight);
                        break;

                    case 5:
                        printf("ENTER THE NEW DATA:");
                        printf("\nHEIGHT:");
                        gets(a.height);
                        break;

                    case 6:
                        printf("ENTER THE NEW DATA:");
                        printf("\nPREVIOUS HEALTH CONDITION:");
                        gets(a.health);
                        break;

                    case 7:
                        printf("ENTER THE NEW DATA:");
                        printf("\nINTERACTED WITH INFECTED:");
                        gets(a.infected);
                        break;

                    case 8:
                        printf("ENTER THE NEW DATA:");
                        printf("\nFELT INFECTED:");
                        gets(a.date);
                        break;

                    case 9:
                        printf("ENTER THE NEW DATA:");
                        printf("\nSYMPTOMS:");
                        gets(a.symptoms);
                        break;

                    case 10:
                        printf("ENTER THE NEW DATA:");
                        printf("\nISOLATED FROM OTHERS? :");
                        gets(a.isolated);
                        break;

                    case 11:
                        printf("ENTER THE NEW DATA:");
                        printf("\nCONSULTED A DOCTOR ? :");
                        gets(a.doctor);
                        break;

                    case 12:
                        printf("ENTER THE NEW DATA:");
                        printf("\nFOUND COVID-19 POSITIVE:");
                        gets(a.positive);
                        break;

                    case 13:
                        printf("ENTER THE NEW DATA:");
                        printf("\nSTATE OF PATIENT:");
                        gets(a.state);
                        break;

                    case 14:
                        printf("ENTER THE NEW DATA:");
                        printf("\nDISTRICT OF PATIENT:");
                        gets(a.district);
                        break;

                    case 15:
                        printf("ENTER THE NEW DATA:");
                        printf("\nEMERGENCY CONTACT NUMBER:");
                        gets(a.emergencyc);
                        break;

                    case 16:
                        printf("ENTER THE NEW DATA:");
                        printf("\nRELATIONSHIP OF EMERGENCY CONTACT:");
                        gets(a.emergencyr);
                        break;

                    case 17:
                        printf("ENTER THE NEW DATA:");
                        printf("\nHOSPITALISATION DATE:");
                        gets(a.emergencyc);
                        break;

                    case 18:
                    	printf("ENTER THE NEW DATA:");
                        printf("\tPATIENT's NAME:");
			            gets(a.name);
						printf("\tSEX:");
			            gets(a.gender);
			            printf("\tAGE:");
			            gets(a.age);
			            printf("\tWEIGHT:");
			            gets(a.weight);
			            printf("\tHEIGHT:");
			            gets(a.height);
			            printf("\tPREVIOUS HEALTH CONTDITION:");
			            gets(a.health);
			            printf("\tINTERACTED WITH INFECTED:");
			            gets(a.infected);
			            printf("\tFELT INFECTED:");
			            gets(a.date);
			            printf("\tSYMPTOMS:");
			            gets(a.symptoms);
			            printf("\tISOLATED FROM OTYHERS ? :");
			            gets(a.isolated);
			            printf("\tCONSULTED A DOCTOR ? :");
			            gets(a.doctor);
			            printf("\tFOUND COVID-19 POSITIVE:");
			            gets(a.positive);
			            printf("\tSTATE OF THE PATIENT:");
			            gets(a.state);
			            printf("\tDISTRICT OF THE PATIENT:");
			            gets(a.district);
			            printf("\tPATIENT'S EMERGENCY CONTACT NUMBER:");
			            gets(a.emergencyc);
			            printf("\tRELATIONSHIP OF EMERGENCY CONTACT WITH PATIENT:");
			            gets(a.emergencyr);
			            printf("\tHOSPITALISATION DATE:");
			            gets(a.datearr);
                        break;

                    case 19:
                        printf("\nPRESS ANY KEY TO GO BACK...\n");
                        getch();
                        return ;
                        break;

                    default:
                        printf("\nYOU TYPED SOMETHING ELSE...TRY AGAIN\n");
                        break;

                    }

                }
                while(num<1||num>20);

                fseek(fp,-sizeof(a),SEEK_CUR);

                fwrite(&a,sizeof(a),1,fp);

                fseek(fp,-sizeof(a),SEEK_CUR);

                fread(&a,sizeof(a),1,fp);

                choice=5;

                break;

            }
        }

        if(choice==5)

        {

            system("cls");

            printf("\n\t\tEDITING COMPLETED...\n");
            printf("--------------------\n");
            printf("THE NEW RECORD IS:\n");
            printf("--------------------\n");
            printf("\nPATIENT'S NAME IS: %s",a.name);
            printf("\nPATIENT's GENDER IS: %s",a.gender);
            printf("\nPATIENT's AGE IS: %s",a.age);
            printf("\nPATIENT's WEIGHT IS: %s",a.weight);
            printf("\nPATIENT's HEIGHT IS: %s",a.height);
            printf("\nPATIENT's PREVIOUS HEALTH CONTDITION : %s",a.health);
            printf("\nPATIENT INTERACTED WITH INFECTED : %s",a.infected);
            printf("\nPATIENT FELT INFECTED : %s",a.date);
            printf("\nPATIENT'S SYMPTOMS: %s",a.symptoms);
            printf("\nISOLATED FROM OTHERS ?: %s",a.isolated);
            printf("\nCONSULTED A DOCTOR ? : %s",a.doctor);
            printf("\nDATE FOUND COVID-19 POSITIVE: %s",a.positive);
            printf("\nSTATE OF THE PATIENT : %s",a.state);
            printf("\nDISTRICT OF THE PATIENT: %s",a.district);
            printf("\nPATIENT's EMERGENCY CONTACT NUMBER : %s",a.emergencyc);
            printf("\nRELATIONSHIP OF EMERGENCY CONTACT WITH PATIENT: %s",a.emergencyr);
            printf("\nHOSPITALISATION DATE: %s",a.datearr);

            fclose(fp);

            printf("\n\n\tWOULD YOU LIKE TO EDIT ANOTHER RECORD.(Y/N)");
            scanf("%c",&choice);
            count++;

        }
        else
        {

            printf("\nTHE RECORD DOES NOT EXIST::\n");
            printf("\nWOULD YOU LIKE TO TRY AGAIN...(Y/N)");
        	scanf("%c",&choice);

        }
    }
    while(choice=='Y'||choice=='y');

    fclose ( fp ) ;
    printf("\tPRESS ENTER TO EXIT EDITING MENU.");
    getch();

}

//*********************************************************
/**************** VIEWING FUNCTION************************/
//*********************************************************

void viewrecord()

{
    system("cls");
    FILE *fp;

    char filename[30];

    printf("\n\n\t\t====================================\n");
    printf("\t\t\t - LIST RECORDS -");
    printf("\n\t\t====================================\n");

    fp=fopen("filename","rb");
    rewind(fp);
    while((fread(&a,sizeof(a),1,fp))==1)
    {
        printf("\n\n\t\t::PRESS ENTER TO VIEW MORE RECORDS!::\n");
      printf("\nPATIENT'S NAME IS: %s",a.name);
      printf("\nPATIENT's GENDER IS: %s",a.gender);
      printf("\nPATIENT's AGE IS: %s",a.age);
      printf("\nPATIENT's WEIGHT IS: %s",a.weight);
      printf("\nPATIENT's HEIGHT IS: %s",a.height);
      printf("\nPATIENT's PREVIOUS HEALTH CONTDITION : %s",a.health);
      printf("\nPATIENT INTERACTED WITH INFECTED : %s",a.infected);
      printf("\nPATIENT FELT INFECTED : %s",a.date);
      printf("\nPATIENT'S SYMPTOMS: %s",a.symptoms);
      printf("\nISOLATED FROM OTHERS ?: %s",a.isolated);
      printf("\nCONSULTED A DOCTOR ? : %s",a.doctor);
      printf("\nDATE FOUND COVID-19 POSITIVE: %s",a.positive);
      printf("\nSTATE OF THE PATIENT : %s",a.state);
      printf("\nDISTRICT OF THE PATIENT: %s",a.district);
      printf("\nPATIENT's EMERGENCY CONTACT NUMBER : %s",a.emergencyc);
      printf("\nRELATIONSHIP OF EMERGENCY CONTACT WITH PATIENT: %s",a.emergencyr);
      printf("\nHOSPITALISATION DATE: %s",a.datearr);

        getch();

    }
    fclose(fp);
	getch();

}


//*********************************************************
/**************** DELETING FUNCTION************************/
//*********************************************************

void deleterecord( )

{

    system("cls");
    FILE *fp,*ft ;
    struct record file ;
    char filename[15],another = 'Y' ,id[16];;
    int choice,check;
    int j=0;
    char pass[8];

    printf("\n\n\t\t====================================\n");
    printf("\t\t\t- DELETE RECORDS -");
    printf("\n\t\t====================================\n\n");

    printf("\nENTER PASSWORD\n");
    int i;
    for(  i=0;i<1;i++)
    {
    	pass[i]=getch();
    	printf("*");
	}
	if (strcmpi(pass,"1")==0)
	{

     printf("\n\t\t*ACCESS GRANTED*\n\n");
   while ( another == 'Y' || another == 'y' )

    {

    	printf("\n\tENTER THE NAME OF PATIENT TO BE DELETED:");
		fflush(stdin);
        gets(filename);
        fp = fopen ("filename", "rb" ) ;
        if ( fp == NULL )
                {
                    printf("\nTHE FILE DOES NOT EXIST");
                    printf("\nPRESS ANY KEY TO GO BACK.");
                    getch();
                    return ;
				}
				ft=fopen("temp","wb");

				if(ft==NULL)
                {
                	printf("\nSYSTEM ERROR");
                    printf("\nPRESS ANY KEY TO GO BACK");
                    getch();
                    return ;
                }
                printf("\n\tENTER THE ID OF RECORD TO BE DELETED:");
                fflush(stdin);
                gets(id);

        		while(fread(&file,sizeof(file),1,fp)==1)

                {

                    if(strcmp(file.id,id)!=0)

                    fwrite(&file,sizeof(file),1,ft);

                }
        fclose(ft);
        fclose(fp);
        remove("filename");
        rename("temp","filename");
        printf("\nDELETED SUCCESFULLY...");
        getch();

        printf("\n\tDO YOU LIKE TO DELETE ANOTHER RECORD.(Y/N):");
        fflush(stdin);
        scanf("%c",&another);

    }


    printf("\n\n\tPRESS ANY KEY TO EXIT...");

    getch();
}
	else
	{
		printf("\nSorry!Invalid password\n");
		exit(0);
	}

}

void login()
{
	int a=0,i=0;
    char uname[10],c=' ';
    char pword[10],code[10];
    char user[10]="Ankit";
    char pass[10]="1234";
    do
{

    printf("\n  ======================  LOGIN FORM  ======================  \n");
    printf(" \n                       ENTER USERNAME:-");
	scanf("%s", &uname);
	printf(" \n                       ENTER PASSWORD:-");
	while(i<10)
	{
	    pword[i]=getch();
	    c=pword[i];
	    if(c==13) break;
	    else printf("*");
	    i++;
	}
	pword[i]='\0';

	i=0;

		if(strcmp(uname,"Ankit")==0 && strcmp(pword,"1234")==0)
	{
	printf("  \n\n\n    WELCOME TO COVID-19 RECORD MANAGEMENT SYSTEM !! YOUR LOGIN IS SUCCESSFUL");
	printf("\n\n\n\t\t\tPress any key to continue...");
	getch();
	break;
	}
	else
	{
		printf("\n        SORRY !!!!  LOGIN IS UNSUCESSFUL");
		a++;

		getch();
		system("cls");

	}
}
	while(a<=2);
	if (a>2)
	{
		printf("\nSorry you have entered the wrong username and password for four times!!!");

		getch();

		}
		system("cls");
}
