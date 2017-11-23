
# react-native-oracle-mobile-cloud

## Getting started

`$ npm install react-native-oracle-mobile-cloud --save`

### Automatic installation

`$ react-native link react-native-oracle-mobile-cloud`

#### iOS
  Do step 4 of Manual installation

#### Android
  Do step 4, 5 and 6 of Manual installation


### Manual installation

#### iOS

1. In XCode, in the project navigator, right click `Libraries` ➜ `Add Files to [your project's name]`
2. Go to `node_modules` ➜ `react-native-oracle-mobile-cloud` and add `RNOracleMobileCloud.xcodeproj`
3. In XCode, in the project navigator, select your project. Add `libRNOracleMobileCloud.a` to your project's `Build Phases` ➜ `Link Binary With Libraries`
4. In XCode, in the project navigator, select your project. Create a file name OMC.plist. Open as source code and put
   ```
    <?xml version="1.0" encoding="UTF-8"?>
    <!DOCTYPE plist PUBLIC "-//Apple//DTD PLIST 1.0//EN" "http://www.apple.com/DTDs/PropertyList-1.0.dtd">
    <plist version="1.0">
    <dict>
    	<key>mobileBackends</key>
    	<dict>
    		<key>xxxxxxx</key>
    		<dict>
    			<key>default</key>
    			<true/>
    			<key>baseURL</key>
    			<string>https:xxxxxxxxxxxxx.com:443</string>
    			<key>appKey</key>
    			<string>xxxxx-xxxxx-xxxx-xxxxx-xxxxxx</string>
    			<key>authorization</key>
    			<dict>
    				<key>authenticationType</key>
    				<string>basic</string>
    				<key>OAuth</key>
    				<dict>
    					<key>tokenEndpoint</key>
    					<string>https://xxxxxx.xxxxxxxx/oauth2/tokens</string>
    					<key>clientID</key>
    					<string>xxxxxx-xxxxx-xxxx-xxxxx-xxxxxxx</string>
    					<key>clientSecret</key>
    					<string>xxxxxxxxxx</string>
    				</dict>
    				<key>Basic</key>
    				<dict>
    					<key>mobileBackendID</key>
    					<string>xxxxxx-xxxxxx-xxxx-xxxxxxx-xxxxxx</string>
    					<key>anonymousKey</key>
    					<string>xxxxxxxxxxxxxxxxx=</string>
    				</dict>
    			</dict>
    		</dict>
    	</dict>
    	<key>logLevel</key>
    	<string>debug</string>
    </dict>
    </plist>
   ```
5. Run your project (`Cmd+R`)<

#### Android

1. Open up `android/app/src/main/java/[...]/MainApplication.java`
  - Add `import com.reactlibrary.RNOracleMobileCloudPackage;` to the imports at the top of the file
  - Add `new RNOracleMobileCloudPackage()` to the list returned by the `getPackages()` method
2. Append the following lines to `android/settings.gradle`:
  	```
  	include ':react-native-oracle-mobile-cloud'
  	project(':react-native-oracle-mobile-cloud').projectDir = new File(rootProject.projectDir, 	'../node_modules/react-native-oracle-mobile-cloud/android')
  	```
3. Insert the following lines inside the dependencies block in `android/app/build.gradle`:
  	```
      compile project(':react-native-oracle-mobile-cloud')
  	```
4. Open up `android/app/src/main/[...]/AndroidManifest.xml`
  - Add `<uses-permission android:name="android.permission.ACCESS_NETWORK_STATE"/>`

5.

6. In `android/app/src/main/   (at the same level as the java and res folders)` create a folder name assets if not exist.
   Move to assets folder and create a file name oracle_mobile_cloud_config.xml
   ```
   <?xml version="1.0" encoding="utf-8" ?>
   <mobileBackends>

      <!--Here are the settings for a single mobileBackend.
      For those apps with multiple mobileBackends, you might need to add
      settings one by one below-->

      <mobileBackend>
          <!--Add the name and version of your mobileBackend as values here-->
          <mbeName>xxxxxxxxxxxxxxxxxx</mbeName>
          <mbeVersion>1.0</mbeVersion>

          <!--Set to true if the current mobileBackend is the default one-->
          <default>true</default>

          <!--Add the appID of client Android here-->
          <appKey>xxxxxxx-xxxx-xxxx-xxxx-xxxxxxx</appKey>

          <!--The base URL goes here-->
          <baseUrl>https://xxxxxxxx.xxxxxxxx.com:443</baseUrl>

          <!--Set it true if you want to get analytics information from UI-->
          <enableAnalytics>true</enableAnalytics>

          <!--Set it true if you want to get location information along with analytics from UI-->
          <enableAnalyticsLocation>true</enableAnalyticsLocation>

          <!--Set it true if you want to get logging information in Logger-->
          <enableLogger>true</enableLogger>

          <!--Add the OAuth Service and secret here -->
          <!--To get the oAuthClientId and oAuthClientSecret, you may go to MCS UI-> Development->
          MobileBackend->Settings -->
          <authorization>
              <!-- Set this to true/false to enabled/disable offline login-->
              <offlineAuthenticationEnabled>true</offlineAuthenticationEnabled>

              <!-- authenticationType goes here set it to basic or oauth-->
              <authenticationType>basic</authenticationType>

              <!-- set these when authenticationType above is basic-->
              <basic>
                  <mobileBackendID>xxxxx-xxxx-xxxx-xxxx-xxxxxx</mobileBackendID>
                  <anonymousKey>xxxxxxxxxxxxxxxxxxxxxxxxxxx=</anonymousKey>
              </basic>

              <!-- set these when authenticationType above is oauth-->
              <oauth>
                  <oAuthTokenEndPoint>https://xxxxx.ixxxxxx.xxxx/oam/oauth2/tokens</oAuthTokenEndPoint>
                  <oAuthClientId>xxxxxx-xxxx-xxxx-xxxx-xxxxxxxxxx</oAuthClientId>
                  <oAuthClientSecret>xxxxxxxxxxxxxxxxxxx</oAuthClientSecret>
              </oauth>
          </authorization>
      </mobileBackend>
    </mobileBackends>
   ```

## Usage
```javascript
import RNOracleMobileCloud from 'react-native-oracle-mobile-cloud';
```

#### Login
```javascript
    RNOracleMobileCloud.loginUser(this.state.usuario, this.state.password,
      (success, data) => {
        if(success) {
          console.log("Success", data);
        } else {
          console.log("Error", data);
        }
    });

    RNOracleMobileCloud.loginAnonymous(
      (success, data) => {
        if(success) {
          console.log("Success", data);
        } else {
          console.log("Error", data);
        }
      });

    RNOracleMobileCloud.logout(
      (success, data) => {
        if(success) {
          console.log("Success", data);
        } else {
          console.log("Error", data);
        }
      });
```

#### Invoke custom api
```javascript
    RNOracleMobileCloud.invokeEndPoint("oracle_dev_api/movies",
      null, //Body for POST, PUT, DELETE
      RNOracleMobileCloud.HTTP_METHOD_GET,
      (success, data) => {
        if(success) {
          console.log("Success", data.moviesList);          
        } else {
          console.log("Error", data);
        }
      });
```

## TODO
  `Location, Storage, Notification, Analytics and Database`
