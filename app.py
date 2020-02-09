from flask import Flask, render_template, redirect, url_for

app = Flask(__name__)
app.config["DEBUG"] = True

@app.route('/wash')
def wash():

    return render_template('layout.html')

if __name__ == '__main__':
    app.run(port="7777")
