const CLIENT_ID = 'YOUR_CLIENT_ID';
const API_KEY = 'YOUR_API_KEY';
const DISCOVERY_DOCS = ["https://www.googleapis.com/discovery/v1/apis/gmail/v1/rest"];
const SCOPES = "https://www.googleapis.com/auth/gmail.readonly https://www.googleapis.com/auth/gmail.send";

let authorizeButton = document.getElementById('authorize_button');
let signoutButton = document.getElementById('signout_button');

function handleClientLoad() {
    gapi.load('client:auth2', initClient);
}

function initClient() {
    gapi.client.init({
        apiKey: API_KEY,
        clientId: CLIENT_ID,
        discoveryDocs: DISCOVERY_DOCS,
        scope: SCOPES
    }).then(() => {
        gapi.auth2.getAuthInstance().isSignedIn.listen(updateSigninStatus);
        updateSigninStatus(gapi.auth2.getAuthInstance().isSignedIn.get());
        authorizeButton.onclick = handleAuthClick;
        signoutButton.onclick = handleSignoutClick;
    });
}

function updateSigninStatus(isSignedIn) {
    if (isSignedIn) {
        authorizeButton.style.display = 'none';
        signoutButton.style.display = 'block';
        listMessages();
    } else {
        authorizeButton.style.display = 'block';
        signoutButton.style.display = 'none';
    }
}

function handleAuthClick(event) {
    gapi.auth2.getAuthInstance().signIn();
}

function handleSignoutClick(event) {
    gapi.auth2.getAuthInstance().signOut();
}

function listMessages() {
    gapi.client.gmail.users.messages.list({
        'userId': 'me',
        'labelIds': 'INBOX',
        'maxResults': 10
    }).then((response) => {
        let messages = response.result.messages;
        let emailListDiv = document.getElementById('email-list');
        emailListDiv.innerHTML = '';
        messages.forEach((message) => {
            getMessage(message.id);
        });
    });
}

function getMessage(messageId) {
    gapi.client.gmail.users.messages.get({
        'userId': 'me',
        'id': messageId
    }).then((response) => {
        let message = response.result;
        let emailListDiv = document.getElementById('email-list');
        let div = document.createElement('div');
        div.className = 'email';
        div.innerHTML = `<p>From: ${getHeader(message.payload.headers, 'From')}</p>
                         <p>Subject: ${getHeader(message.payload.headers, 'Subject')}</p>
                         <p>${getBody(message.payload)}</p>`;
        emailListDiv.appendChild(div);
    });
}

function getHeader(headers, name) {
    for (let i = 0; i < headers.length; i++) {
        if (headers[i].name === name) {
            return headers[i].value;
        }
    }
    return '';
}

function getBody(payload) {
    let encodedBody = '';
    if (typeof payload.parts === 'undefined') {
        encodedBody = payload.body.data;
    } else {
        encodedBody = getHTMLPart(payload.parts);
    }
    encodedBody = encodedBody.replace(/-/g, '+').replace(/_/g, '/');
    return decodeURIComponent(escape(window.atob(encodedBody)));
}

function getHTMLPart(parts) {
    for (let i = 0; i < parts.length; i++) {
        if (typeof parts[i].parts === 'undefined') {
            if (parts[i].mimeType === 'text/html') {
                return parts[i].body.data;
            }
        } else {
            return getHTMLPart(parts[i].parts);
        }
    }
    return '';
}

function sendEmail() {
    const headers = new Headers();
    headers.append('Authorization', `Bearer ${gapi.auth.getToken().access_token}`);
    headers.append('Content-Type', 'application/json');

    const raw = JSON.stringify({
        "raw": btoa(
            "From: me\r\n" +
            "To: recipient@example.com\r\n" +
            "Subject: Subject Text\r\n\r\n" +
            "The body text"
        )
    });

    const requestOptions = {
        method: 'POST',
        headers: headers,
        body: raw,
        redirect: 'follow'
    };

    fetch("https://www.googleapis.com/gmail/v1/users/me/messages/send", requestOptions)
        .then(response => response.text())
        .then(result => console.log(result))
        .catch(error => console.log('error', error));
}
