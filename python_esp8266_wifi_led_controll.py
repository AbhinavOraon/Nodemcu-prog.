import tkinter#python deafult GUI module
import urllib.request#defines function and_ classes which help in opening urls
#url handling module for python
root_url = "http://192.168.43.141"
window=tkinter.Tk()
window.title("GUI")
def sendRequest(url):
	n = urllib.request.urlopen(url) # send request to ESP

def a():
    sendRequest(root_url+"/ledon")
    print("Led is on")

def b():
    sendrequest(root_url+"/ledoff")
    print("Led is off")
# code to add widgets


while True:
    headline=tkinter.Label(window,text="Led Control with Pyrhon Tkinter (Esp8266)",fg="red",font=("ANUDAW",25))
    headline.grid(column=2,row=0)
    ON=tkinter.Button(window,text="ON",command=a,fg="yellow",bg="green",font=("Lobster 1.4",25))
    OFF=tkinter.Button(window,text="OFF",command=b,fg="yellow",bg="green",font=("Lobster 1.4",25))
    ON.grid(column=2,row=1)
    OFF.grid(column=2,row=2)
    window.mainloop()
		
 