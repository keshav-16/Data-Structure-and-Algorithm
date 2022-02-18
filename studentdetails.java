import java.util.*; 

  

class student{ 

static int count=0; 

int regNo; 

String fullName;	 

GregorianCalendar gc=new GregorianCalendar(); 

short sem; 

float GPA; 

float CGPA; 

int no; 

  

student(){ 

regNo=0; 

fullName=""; 

sem=0; 

GPA=0; 

CGPA=0; 

gc=new GregorianCalendar(2000,1,1); 

count++; 

no=count; 

} 

  

student(int year,int month,int date,String name,short senstr,float gpa,float cgpa){ 

fullName=name; 

sem=senstr; 

GPA=gpa; 

CGPA=cgpa; 

gc=new GregorianCalendar(year,month,date); 

count++; 

no=count; 

int yr=gc.get(Calendar.YEAR)%100; 

regNo=yr*100+no;	 

} 

  

@Override

public String toString(){

System.out.print("Registration number:"+regNo+"\t"); 

System.out.print("Full Name:"+fullName+"\t"); 

System.out.print(" Date of join:"+gc.get(Calendar.DATE)+"/"+gc.get(Calendar.MONTH)+"/"+gc.get(Calendar.YEAR)+"\t"); 

System.out.print("Semester:"+sem+"\t"); 

System.out.print("GPA:"+GPA+"\t"); 

System.out.print("CGPA:"+CGPA+"\n");
return "";	 

} 
static void sorter(student[] stu) {

String[] arr=new String[count];
for(int i=0;i<count;i++){
arr[i]=stu[i].fullName;
}
Arrays.sort(arr);
for(int i=0;i<count;i++){
System.out.println(arr[i]);
}
System.out.println("The list of sorted names of students: ");

for(int i=0;i<count;i++){
System.out.println(arr[i]);
}
}
static void search(String sub,student[] stu){
int counter=0;
System.out.println("All the names with the substring "+sub+" are :");
for(int i=0;i<count;i++){
if(stu[i].fullName.contains(sub)){
System.out.println(stu[i].fullName);
}
}
}
} 

  

  

class studentdetails{ 

	

public static void main(String[] args){ 

  

Scanner sc = new Scanner(System.in); 

  

student[] stu = new student[5]; 

  

int date,month,year; 

String fullName; 

short sem; 

float gpa,cgpa; 

  

for(int i=0;i<5;i++){ 

System.out.println("Enter details for student "+(i+1)+":"); 

System.out.print("Enter your name : "); 

fullName = sc.next(); 

System.out.print("Enter semester : "); 

sem = sc.nextShort(); 

System.out.print("Enter GPA of current semester : "); 

gpa = sc.nextFloat(); 

System.out.print("Enter CGPA of current year : "); 

cgpa = sc.nextFloat(); 

System.out.print("Enter date of joining : "); 

date = sc.nextInt(); 

System.out.print("Enter month of joining : "); 

month = sc.nextInt(); 

System.out.print("Enter year of joining : "); 

year = sc.nextInt(); 

System.out.println(); 

stu[i] = new student(year,month,date,fullName,sem,gpa,cgpa); 

} 

System.out.println();
System.out.println("Enter the substring to be searched: ");
String sub = sc.next();
stu.search(sub,stu);
System.out.println();
System.out.println("The sorted list of names is: ");
stu.sorter(stu);

for(int j=0;j<5;j++){ 

stu[j].toString(); 

} 

} 

} 