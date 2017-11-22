
# react-native-oracle-mobile-cloud

## Getting started

`$ npm install react-native-oracle-mobile-cloud --save`

### Mostly automatic installation

`$ react-native link react-native-oracle-mobile-cloud`

### Manual installation


#### iOS

1. In XCode, in the project navigator, right click `Libraries` ➜ `Add Files to [your project's name]`
2. Go to `node_modules` ➜ `react-native-oracle-mobile-cloud` and add `RNOracleMobileCloud.xcodeproj`
3. In XCode, in the project navigator, select your project. Add `libRNOracleMobileCloud.a` to your project's `Build Phases` ➜ `Link Binary With Libraries`
4. Run your project (`Cmd+R`)<

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
4. Open up `android/app/src/main/[...]/AndroidManifest.xml.java`
  - Add `<uses-permission android:name="android.permission.ACCESS_NETWORK_STATE"/>`

#### Windows
[Read it! :D](https://github.com/ReactWindows/react-native)

1. In Visual Studio add the `RNOracleMobileCloud.sln` in `node_modules/react-native-oracle-mobile-cloud/windows/RNOracleMobileCloud.sln` folder to their solution, reference from their app.
2. Open up your `MainPage.cs` app
  - Add `using Oracle.Mobile.Cloud.RNOracleMobileCloud;` to the usings at the top of the file
  - Add `new RNOracleMobileCloudPackage()` to the `List<IReactPackage>` returned by the `Packages` method


## Usage
```javascript
import RNOracleMobileCloud from 'react-native-oracle-mobile-cloud';

// TODO: What to do with the module?
RNOracleMobileCloud;
```