from tkinter import *
from tkinter import messagebox

window=Tk()
window.minsize(width=300,height=200)
window.config(padx=30,pady=30)
window.title("BMI Calculator")

# ................................Calculate BMI...................................#
def calculate():
    bmi_text.delete("1.0",END)
    height=height_entry.get()
    weight=weight_entry.get()
    if len(height)!=0 and len(weight)!=0:
        height=float(height)
        weight=float(weight)
        # if range(height,0.6,2.1) and range(weight,2,200):
        if 0.6<height<=2.1 and 2<weight<200:
            bmi=round(weight/height**2,2)
            bmi_text.insert(END,f"{bmi}")
        else:
            messagebox.showwarning(title="Warning",message="Invalid Height or Weight")
    else:
        messagebox.showerror(title="Error",message="Do not leave any empty box!!")
    
    

# ................................Label...................................#
height_label=Label(text="Height ( in meters )")
height_label.grid(row=0,column=0,padx=5,pady=5)
weight_label=Label(text="Weight ( in kgs )")
weight_label.grid(row=1,column=0,padx=5,pady=5)
bmi_label=Label(text="BMI")
bmi_label.grid(row=2,column=0,padx=5,pady=5)

# ................................Entry...................................#
height_entry=Entry(width=20)
height_entry.grid(row=0,column=1,padx=5,pady=5)
weight_entry=Entry(width=20)
weight_entry.grid(row=1,column=1,padx=5,pady=5)
height_entry.focus()

# ................................Text...................................#
bmi_text=Text(width=15,height=1)
bmi_text.grid(row=2,column=1,padx=5,pady=5)

# ................................Button...................................#
calculate_button=Button(text="Calculate",padx=2,pady=2,command=calculate)
calculate_button.grid(row=3,columnspan=2)





window.mainloop()