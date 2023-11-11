import smtplib
from email.mime.text import MIMEText
import subprocess

# Function to get system uptime
def get_uptime():
    result = subprocess.run(["uptime"], stdout=subprocess.PIPE, text=True)
    return result.stdout

# Email configuration
sender_email = "me1556011@gmail.com"
receiver_email = "me1556011@outlook.com"
password = "snnz ystk sbld igha"
subject = "Uptime Report"
message = get_uptime()

# Create and send the email
msg = MIMEText(message)
msg["From"] = sender_email
msg["To"] = receiver_email
msg["Subject"] = subject

# Send the email using your SMTP server
with smtplib.SMTP("smtp.gmail.com", 587) as server:
    server.starttls()
    server.login(sender_email, password)
    server.sendmail(sender_email, receiver_email, msg.as_string())
