import os
from flask import Flask, render_template_string
from markupsafe import escape

server = Flask(__name__)

@server.route("/")
def index():
    html = """
    <h1>My FTP Server</h1>
    <b>LS/[path]</b>: List files in [path].<br>
    <b>CAT/[path]</b>: Cat file at [path].
    """
    return html

@server.route("/LS/", defaults={"p": "."})
@server.route("/LS/<path:p>/")
def ls(p):
    ls_out = os.listdir(escape(p))
    return "<br>".join(ls_out)

@server.route("/CAT/<path:p>/")
def cat(p):
    with open(escape(p), "r") as f:
        cat_out = escape(f.read())
    return render_template_string("<pre>{{ content }}</pre>", content=cat_out)

if __name__ == "__main__":
    server.run(debug=True)

