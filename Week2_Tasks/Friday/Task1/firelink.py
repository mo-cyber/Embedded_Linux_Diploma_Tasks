import webbrowser

links = {'facebook' : 'https://www.facebook.com/',
         'youtube' : 'https://www.youtube.com/',
         'github' : 'https://github.com/'}

def firefox (link):
    webbrowser.open(link)