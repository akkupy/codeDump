const nodemailer = require('nodemailer');
require("dotenv").config();


module.exports.sendVerificationOtp = (email,otp) =>{
    const msg = {
        from: process.env.FROM,
        to: email,
        subject: "Email Verification OTP",
        html:`
        <!DOCTYPE html>
        <html lang="en">
          <head>
            <meta charset="UTF-8" />
            <meta http-equiv="X-UA-Compatible" content="IE=edge" />
            <meta name="viewport" content="width=device-width, initial-scale=1.0" />
            <title>Enthouse OTP Template</title>
            <!--Fontawesome Icon CDN -->
            <link
              rel="stylesheet"
              href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/5.15.3/css/all.min.css"
            />
        
            <!-- css -->
            <style>
              body {
                margin: 0;
                padding: 20px;
                background-color: #faefed;
                display: flex;
                justify-content: center;
                align-items: center;
              }
              .logo {
                font-size: 0;
              }
              .footer-logo {
                margin-left: 33rem;
                font-size: 0;
              }
              .image {
                width: 6rem;
                height: 6rem;
              }
              .footer-image {
                width: 6rem;
                height: 10rem;
              }
              .brand-name {
                display: inline;
                font-size: 24px;
                margin-left: 15px;
                font-weight: 600;
              }
        
              .wrapper {
                width: 100%;
                table-layout: fixed;
                background-color: #faefed;
                padding-bottom: 50px;
              }
              .main {
                background-color: white;
                margin: 0 auto;
                width: 100%;
                max-width: 600px;
                border-spacing: 0;
                font-family: sans-serif;
              }
              a {
                text-decoration: none;
              }
              .footer {
                font-size: small;
                color:#b3b3b3;
              }
        
              /* ---------------------------- Media Queries ------------------------ */
        
              /* mobile responsive */
              @media (min-width: 320px) and (max-width: 480px) {
                .footer-logo {
                  margin-left: 12rem;
                }
                .footer-links {
                  font-size: 0.8rem;
                }
              }
            </style>
          </head>
          <body>
            <centre class="wrapper">
              <table class="main" style="width: 100%">
                <tr>
                  <td style="
                  padding: 3px 0px 3px 0px;
                  
                  text-align: left;
                  background-color: #141414
                ">
                    <!--------------------------------------- header --------------------------------------------->
                    
                          <a class="logo" href="https://www.enthouse.in/" target="_blank"
                            ><img class="image" src="https://www.enthouse.in/ent.png" />
                          </a>
                        
                  </td>
                </tr>
                <!--------------------------------------- content body -------------------------------------------->
                <tr>
                <td style="padding: 0px 20px 0px 35px; font-size: 15px; text-align:justify">
                <p><b>Dear User,</b></p>
                <p>
                  You are in the process of registering an account. The verification code is:</p>
                <span style="color:#d00000; font-size: x-large;"><b>${otp}</b></span>
                <p>Thank You,</p>
                <p>Regards,</p>
                <p><b>Team Enthouse.</b></p>
              </td>
                </tr>
        
                <!------------------------------------- footer --------------------------------------->
                <tr>
                  <td style="background-color: #141414">
                    <table width="0%">
                      <tr>
                        <td style="padding: 20px">
                          
                          <div class="footer">
                            The email is sent by the system automatically. Please do not reply. Thank you!
                          </div>
                          
                        </td>
                      </tr>
                    </table>
                  </td>
                </tr>
              </table>
            </centre>
          </body>
        </html>
        `
    };
    nodemailer.createTransport({
        service: 'gmail',
        auth:{
            user:process.env.NODEMAILER_USER,
            pass:process.env.NODEMAILER_PASSWORD,
        },
        port:465,
        host:'smtp.gmail.com'
    })
    .sendMail(msg,(err)=>{
        if(err){
            console.log('Error occurs',err);
            return "failed";
        }else{
            console.log('Email sent');
            return "success";
        }
    })
};

module.exports.sendSuccessRegistration = (email,user_name,phone) =>{
    const msg = {
        from: process.env.FROM,
        to: email,
        subject: "Registration Successful",
        html:`
        <!DOCTYPE html>
    <html lang="en">
    <head>
        <meta charset="UTF-8" />
        <meta http-equiv="X-UA-Compatible" content="IE=edge" />
        <meta name="viewport" content="width=device-width, initial-scale=1.0" />
        <title>Register</title>
        <!--Fontawesome Icon CDN -->
        <link
        rel="stylesheet"
        href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/5.15.3/css/all.min.css"
        />

        <!-- css -->
        <style>
        body {
            margin: 0;
            padding: 20px;
            background-color: #faefed;
            display: flex;
            justify-content: center;
            align-items: center;
        }
        label{
            font-weight: 700;
            margin: 10px;
        }
        .logo {
            font-size: 0;
        }
        .footer-logo {
            margin-left: 33rem;
            font-size: 0;
        }
        .image {
            width: 6rem;
            height: 6rem;
        }
        .footer-image {
            width: 6rem;
            height: 10rem;
        }
        .brand-name {
            display: inline;
            font-size: 24px;
            margin-left: 15px;
            font-weight: 600;
        }

        .wrapper {
            width: 100%;
            table-layout: fixed;
            background-color: #faefed;
            padding-bottom: 50px;
        }
        .main {
            background-color: white;
            margin: 0 auto;
            width: 100%;
            max-width: 600px;
            border-spacing: 0;
            font-family: sans-serif;
        }
        a {
            text-decoration: none;
        }
        .footer {
            font-size: small;
            color: #b3b3b3;
        }

        /* ---------------------------- Media Queries ------------------------ */

        /* mobile responsive */
        @media (min-width: 320px) and (max-width: 480px) {
            .footer-logo {
            margin-left: 12rem;
            }
            .footer-links {
            font-size: 0.8rem;
            }
        }
        </style>
    </head>
    <body>
        <centre class="wrapper">
        <table class="main" style="width: 100%">
            <tr>
            <td
                style="
                padding: 3px 0px 3px 0px;

                text-align: left;
                background-color: #141414;
                "
            >
                <!--------------------------------------- header --------------------------------------------->

                <a class="logo" href="https://www.enthouse.in/" target="_blank"
                ><img class="image" src="https://www.enthouse.in/ent.png" />
                </a>
            </td>
            </tr>
            <!--------------------------------------- content body -------------------------------------------->
            <tr>
            <td
                style="
                padding: 0px 20px 0px 35px;
                font-size: 15px;
                text-align: justify;
                "
            >
                <h1>Thanks for joining Enthouse</h1>
                <p><b>Dear ${user_name},</b></p>
                <p>You're ready to start watching content.</p>
                <div
                class=""
                style="border-radius: 12px; border-color: #474747; padding: 10px; background-color: #e8e8e884; display: flex; flex-direction: column;"
                >
                <b>Your Account Information : </b><br/>
                <label>Email</label>&nbsp;&nbsp;&nbsp;&nbsp;${email}<br/>
                <label>Name</label>&nbsp;&nbsp;&nbsp;&nbsp;${user_name}<br/>
                <label>Phone No.</label>&nbsp;&nbsp;&nbsp;&nbsp;${phone}
            </div>
                <p>Thank You,</p>
                <p>Regards,</p>
                <p><b>Team Enthouse.</b></p>
            </td>
            </tr>

            <!------------------------------------- footer --------------------------------------->
            <tr>
            <td style="background-color: #141414">
                <table width="0%">
                <tr>
                    <td style="padding: 20px">
                    <div class="footer">
                        By joining Enthouse, you've agreed to our
                        <a href="https://www.enthouse.in/terms-and-conditions"
                        >Terms & Conditions</a
                        >
                        and
                        <a href="https://www.enthouse.in/privacy-policy"
                        >Privacy Policy.</a
                        >
                    </div>
                    </td>
                </tr>
                </table>
            </td>
            </tr>
        </table>
        </centre>
    </body>
    </html>
        `
    };
    nodemailer.createTransport({
        service: 'gmail',
        auth:{
            user:process.env.NODEMAILER_USER,
            pass:process.env.NODEMAILER_PASSWORD,
        },
        port:465,
        host:'smtp.gmail.com'
    })
    .sendMail(msg,(err)=>{
        if(err){
            console.log('Error occurs',err);
            return "failed";
        }else{
            console.log('Email sent');
            return "success";
        }
    })
};