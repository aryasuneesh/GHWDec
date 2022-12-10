from google.oauth2.credentials import Credentials

# Replace with your own credentials
creds = Credentials.from_authorized_user_info(info={"client_id": "YOUR_CLIENT_ID", "client_secret": "YOUR_CLIENT_SECRET", "refresh_token": "YOUR_REFRESH_TOKEN"})

service = build("sheets", "v4", credentials=creds)

import requests
from bs4 import BeautifulSoup

# Replace with the URL of the website that you want to scrape
url = "https://www.example.com"

# Send a request to the website and get the HTML response
response = requests.get(url)

# Use BeautifulSoup to parse the HTML response
soup = BeautifulSoup(response.text, "html.parser")

# Extract all of the links on the page
links = soup.find_all("a")

# Replace with the ID of the Google Sheet that you want to save the data to
spreadsheet_id = "YOUR_SPREADSHEET_ID"

# Replace with the range in the Google Sheet where you want to save the data
range_name = "Sheet1!A1"

# Replace with the data that you want to save to the Google Sheet
values = [
    ["Link 1", "https://www.link1.com"],
    ["Link 2", "https://www.link2.com"],
    ["Link 3", "https://www.link3.com"],
]

# Use the spreadsheets.values.append method to save the data to the Google Sheet
response = service.spreadsheets().values().append(
    spreadsheetId=spreadsheet_id,
    range=range_name,
    valueInputOption="RAW",
    body={"values": values}
).execute()
