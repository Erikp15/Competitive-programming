from flask import Flask, render_template

app = Flask(__name__)

@app.route("/")
@app.route("/test")
def hello():
    return render_template("home.html")

@app.route("/about")
def test():
    return "<h1>test</h1>"

if __name__ == '__main__':
    app.run(debug=True)