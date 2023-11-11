import pywhatkit as kit

# Specify the target phone number with the country code
target_number = "+201003667700"  # Replace with the recipient's phone number

# Message to send
message = "Holaaa!"

# Send the WhatsApp message
kit.sendwhatmsg(target_number, message, 0, 0)
