import firelink

while True:
    website = input('Choose a website to open (facebook, youtube, github): ')
    firelink.firefox(firelink.links[website])
