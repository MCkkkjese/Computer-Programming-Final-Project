import smtplib
import email.message
import time

msg = email.message.EmailMessage()
def main(master, slave, title, content, smtp, tcp, password):
    msg["From"] = master
    msg["To"] = slave
    msg["Subject"] = title
    msg_time = time.strftime("%m/%d/%Y %H:%M:%S", time.localtime())
    msg.set_content("{}, {}".format(content, msg_time))
    
    server = smtplib.SMTP_SSL(smtp, tcp)
    server.login(master, password)
    server.send_message(msg)
    server.close()

if __name__ == "__main__":
    main()

'''
1. Gmail的SMTP伺服器為 smtp.gmail.com
2. Gmail的TCP埠為 465
3. 以Gmail進行郵件發送，須先取得應用程式密碼
4. master為寄件人email地址，slave為收件人email地址
'''