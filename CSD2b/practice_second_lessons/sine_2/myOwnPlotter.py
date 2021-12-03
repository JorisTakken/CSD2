from tkinter import *

height = "500"
width = "500"

  
top = Tk()  
  
top.geometry("500x500")  



  
#creating a simple canvas  
plot = Canvas(top,bg = "pink",height = height,width = width)  
  
plot.create_line(0, 0, height, width, fill="#476042", width=2)

i = 0
i_str = ''
while i < 1000:
  i_str = i
  i_stri = str(i_str)
  plot.create_line(0, 0, height + (i_stri), width + (i_stri), fill="#476042", width=2)
  i += 1




  
plot.pack()  
  
top.mainloop()  