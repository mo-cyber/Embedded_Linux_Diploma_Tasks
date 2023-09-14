import smtplib
import time
from email.mime.text import MIMEText
from email.mime.multipart import MIMEMultipart
from geopy.geocoders import Nominatim
import psutil

# Function to get the device's location
def get_location():
    geolocator = Nominatim(user_agent="task11")
    location = geolocator.geocode("Kerdasa, Giza, Egypt")
    if location:
        return location.address
    else:
        return "Location not available"

# Function to send an email
def send_email():
    # Email configuration
    sender_email = "xxxxx@gmail.com"  # Replace with your email
    sender_password = "xxxxx"       # Replace with your password
    recipient_email = "xxxxx@outlook.com"  # Replace with your friend's email

    # Create message
    subject = "Device Location Update"
    message = f"Hello,\n\nYour device is currently at: {get_location()}"

    msg = MIMEMultipart()
    msg["From"] = sender_email
    msg["To"] = recipient_email
    msg["Subject"] = subject
    msg.attach(MIMEText(message, "plain"))

    # Send email
    try:
        server = smtplib.SMTP("smtp.gmail.com", 587)
        server.starttls()
        server.login(sender_email, sender_password)
        server.sendmail(sender_email, recipient_email, msg.as_string())
        server.quit()
        print("Email sent successfully!")
    except Exception as e:
        print(f"Error sending email: {str(e)}")
def is_device_on(process_name):
    for process in psutil.process_iter(attrs=['name']):
        if process.info['name'] == process_name:
            return True
    return False

# Main loop
while True:
    device_process_name = "Code.exe"
    # Check if the device is on (you may need to implement a mechanism to check device status)
    device_on = is_device_on(device_process_name)  # Replace with your method of checking device status

    if device_on:
        send_email()
    else:
        print('xx')
    
    # Wait for some time before checking again (e.g., every hour)
    time.sleep(3600)  # Sleep for 1 hour
