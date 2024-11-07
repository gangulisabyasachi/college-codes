import tkinter as tk

def display_text():
    # Get text from the entry widget and update the label
    entered_text = entry.get()
    label.config(text=entered_text)

# Create the main application window
root = tk.Tk()
root.title("Text Display")
root.geometry("300x150")  # Set the window size for better layout

# Create an entry widget
entry = tk.Entry(root, width=30)
entry.pack(pady=10)

# Create a button that calls display_text when clicked
button = tk.Button(root, text="Display Text", command=display_text)
button.pack(pady=5)

# Create a label to display the entered text
label = tk.Label(root, text="", fg="blue")
label.pack(pady=10)

# Run the application
root.mainloop()
