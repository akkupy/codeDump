from flask import Flask,render_template

app = Flask(__name__)

@app.route('/')
def Hello():
    return render_template('Hello.html')

if __name__ == '__main__':
    app.run(debug = True)