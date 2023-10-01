from tkinter import *


window=Tk()
window.config(padx=20,pady=20)


# ................................Functions...................................#
def return_credits(grade):
    match grade:
        case 'S':return 10
        case 'A':return 9
        case 'B':return 8
        case 'C':return 7
        case 'D':return 6
        case 'E':return 5
        case default:
            return 0


def submit():
    sum_credit_obt=0
    x=return_credits((grade_1.get()).upper())*4
    credit_obt_1.config(text=f"{x}")
    sum_credit_obt+=x
    x=return_credits((grade_2.get()).upper())*4
    credit_obt_2.config(text=f"{x}")
    sum_credit_obt+=x
    x=return_credits((grade_3.get()).upper())*3
    credit_obt_3.config(text=f"{x}")
    sum_credit_obt+=x
    x=return_credits((grade_4.get()).upper())*4
    credit_obt_4.config(text=f"{x}")
    sum_credit_obt+=x
    total_credit_obt.config(text=f"{sum_credit_obt}")
    sgpa_obt.config(text=f"{round(sum_credit_obt/15,2)}")



# ................................Label...................................#
name=Label(text="Name")
name.grid(column=0,row=0,pady=5)

roll_num=Label(text="Roll num")
roll_num.grid(column=0,row=1,pady=5)

reg_num=Label(text="Reg.no")
reg_num.grid(column=3,row=0)

serial_num=Label(text="Sl.No")
serial_num.grid(column=0,row=2,padx=5,pady=5)

subject=Label(text="Subject")
subject.grid(column=1,row=2)

grade=Label(text="Grade")
grade.grid(column=2,row=2)

sub_credit=Label(text="Sub Credit")
sub_credit.grid(column=3,row=2)

credit_obt=Label(text="Credit Obtained")
credit_obt.grid(column=4,row=2)

num_1=Label(text="1")
num_1.grid(column=0,row=3)

num_2=Label(text="2")
num_2.grid(column=0,row=4)

num_3=Label(text="3")
num_3.grid(column=0,row=5)

num_4=Label(text="4")
num_4.grid(column=0,row=6)

sub_1=Label(text="CS 201")
sub_1.grid(column=1,row=3,padx=5,pady=5)

sub_2=Label(text="CS 202")
sub_2.grid(column=1,row=4,padx=5,pady=5)

sub_3=Label(text="MA 201")
sub_3.grid(column=1,row=5,padx=5,pady=5)

sub_4=Label(text="EC 201")
sub_4.grid(column=1,row=6,padx=5,pady=5)

credit_1=Label(text="4")
credit_1.grid(column=3,row=3)

credit_2=Label(text="4")
credit_2.grid(column=3,row=4)

credit_3=Label(text="3")
credit_3.grid(column=3,row=5)

credit_4=Label(text="4")
credit_4.grid(column=3,row=6)

total_credit=Label(text="Total Credit")
total_credit.grid(column=3,row=7,padx=5,pady=5)

sgpa=Label(text="SGPA")
sgpa.grid(column=3,row=8,padx=5,pady=5)

credit_obt_1=Label(text="")
credit_obt_1.grid(column=4,row=3)

credit_obt_2=Label(text="")
credit_obt_2.grid(column=4,row=4)

credit_obt_3=Label(text="")
credit_obt_3.grid(column=4,row=5)

credit_obt_4=Label(text="")
credit_obt_4.grid(column=4,row=6)

total_credit_obt=Label(text="")
total_credit_obt.grid(column=4,row=7)

sgpa_obt=Label(text="")
sgpa_obt.grid(column=4,row=8)


# ................................Entry...................................#
name_entry=Entry(width=20)
name_entry.grid(column=1,row=0,columnspan=2)

roll_num_entry=Entry(width=20)
roll_num_entry.grid(column=1,row=1,columnspan=2)

grade_1=Entry(width=15)
grade_1.grid(column=2,row=3,padx=3,pady=3)

grade_2=Entry(width=15)
grade_2.grid(column=2,row=4,padx=3,pady=3)

grade_3=Entry(width=15)
grade_3.grid(column=2,row=5,padx=3,pady=3)

grade_4=Entry(width=15)
grade_4.grid(column=2,row=6,padx=3,pady=3)

reg_num_entry=Entry(width=20)
reg_num_entry.grid(column=4,row=0)


# ................................Button...................................#
submit=Button(text="Submit",bg="green",command=submit,width=13)
submit.grid(column=2,row=9)




window.mainloop()