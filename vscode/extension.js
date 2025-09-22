const vscode = require('vscode');

function hello() {
    vscode.window.showInformationMessage('pony/hello');
}

async function activate(context) {
    vscode.window.showInformationMessage('pony/activate');
    context.subscriptions.push(
        vscode.commands.registerCommand('dponyatov.pony.hello', hello)
    );
}

function deactivate() {
    vscode.window.showInformationMessage('pony/deactivate');
}

module.exports = {
    activate,
    deactivate,
    hello,
};
