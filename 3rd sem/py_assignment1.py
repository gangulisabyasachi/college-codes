import tkinter as tk

# Create the main window
root = tk.Tk()
root.title("My First GUI")

# Create a label widget with "Hello, World!" text
label = tk.Label(root, text="Hello, World!")
label.pack(pady=20)

# Run the application
root.mainloop()