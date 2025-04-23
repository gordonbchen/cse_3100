from flask import Flask, jsonify, abort, request

server = Flask(__name__)

# http://127.0.0.1:7500/myapi/add/5/7
@server.route('/myapi/add/<int:a>/<int:b>')
def add(a, b):
    res = a + b
    return jsonify({'result': res})


if __name__ == "__main__":
    server.run(host='127.0.0.1', port=7500)
