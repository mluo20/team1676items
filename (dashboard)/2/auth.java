// (Receive authCode via HTTPS POST)


if (request.getHeader('X-Requested-With') == null) {
  // Without the `X-Requested-With` header, this request could be forged. Aborts.
}

// Set path to the Web application client_secret_*.json file you downloaded from the
// Google API Console: https://console.developers.google.com/apis/credentials
// You can also find your Web application client ID and client secret from the
// console and specify them directly when you create the GoogleAuthorizationCodeTokenRequest
// object.
String CLIENT_SECRET_FILE = "http://dashboard.team1676.com/2/backend/client_secret_178662378799-g65hoifhubripj63ghkrvleoa2gp4jlp.apps.googleusercontent.com.json";

// Exchange auth code for access token
GoogleClientSecrets clientSecrets =
    GoogleClientSecrets.load(
        JacksonFactory.getDefaultInstance(), new FileReader(CLIENT_SECRET_FILE));
GoogleTokenResponse tokenResponse =
          new GoogleAuthorizationCodeTokenRequest(
              new NetHttpTransport(),
              JacksonFactory.getDefaultInstance(),
              "https://www.googleapis.com/oauth2/v4/token",
              clientSecrets.getDetails().getClientId(),
              clientSecrets.getDetails().getClientSecret(),
              authCode,
              http://dashboard.team1676.com/2/)  // Specify the same redirect URI that you use with your web
                             // app. If you don't have a web version of your app, you can
                             // specify an empty string.
                             
              .execute();

String accessToken = tokenResponse.getAccessToken();

// Use access token to call API
GoogleCredential credential = new GoogleCredential().setAccessToken(accessToken);
Drive drive =
    new Drive.Builder(new NetHttpTransport(), JacksonFactory.getDefaultInstance(), credential)
        .setApplicationName("Larry's Testing")
        .build();
File file = drive.files().get("appfolder").execute();

// Get profile info from ID token
GoogleIdToken idToken = tokenResponse.parseIdToken();
GoogleIdToken.Payload payload = idToken.getPayload();
String userId = payload.getSubject();  // Use this value as a key to identify a user.
String email = payload.getEmail();
boolean emailVerified = Boolean.valueOf(payload.getEmailVerified());
String name = (String) payload.get("name");
String pictureUrl = (String) payload.get("picture");
String locale = (String) payload.get("locale");
String familyName = (String) payload.get("family_name");
String givenName = (String) payload.get("given_name");