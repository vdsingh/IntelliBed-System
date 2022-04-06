import pyrebase
config = {
  "apiKey": "apiKey",
  "authDomain": "projectId.firebaseapp.com",
  "databaseURL": "https://databaseName.firebaseio.com",
  "storageBucket": "projectId.appspot.com"
}
firebase = pyrebase.initialize_app(config)
auth = firebase.auth()
db = firebase.database()
SorR = input("[S]ign in or [R]egister\n")
email=input("Enter Email:\n")
password=input("Enter Password:\n")
if SorR.lower() == 's':
    user=auth.sign_in_with_email_and_password(email, password)
elif SorR.lower() == 'r':
    user=auth.create_user_with_email_and_password(email, password)
    print('Verify Email')
    auth.send_email_verification(user['idToken'])

db.child()