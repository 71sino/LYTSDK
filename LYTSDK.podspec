

Pod::Spec.new do |s|


  s.name         = "LYTSDK"

  s.version      = "2.0.14.7"

  s.summary      = "an iOS communication SDK "
  s.description  = "an iOS communication SDK create by HHLY ,you need go to the HHLY registing you app first"

  s.homepage     = "https://www.71ant.com"

  s.license      = "MIT"
  
  s.author       = { "71sino" => "dev@71sino.com" }
  
  s.platform     = :ios, "8.0"

  s.source       = { :git => "https://github.com/71sino/LYTSDK.git", :tag => s.version }


  s.requires_arc = true

  s.exclude_files = "Classes/*.md"

  s.default_subspec = 'Core'

 
  s.subspec 'LYTFoundation' do |f|
    
    f.framework = "Foundation"
    f.source_files = 'Classes/LYTFoundation/**/*.{h,a}'
    f.vendored_libraries = "Classes/LYTFoundation/*.a"
    f.public_header_files = 'Classes/LYTFoundation/**/*.h'

  end

  s.subspec 'LYTCommonLib' do |com|
    
    com.framework = "Foundation"
    com.source_files = 'Classes/LYTCommonLib/**/*.{h,a}'
    com.vendored_libraries = "Classes/LYTCommonLib/*.a"
    com.public_header_files = 'Classes/LYTCommonLib/**/*.h'

  end


  s.subspec 'Core' do |sdk|

    sdk.frameworks = "UIKit", "CoreTelephony", "UserNotifications"
    sdk.libraries = "z", "xml2", "sqlite3.0"
    sdk.dependency 'LYTSDK/LYTFoundation'
    sdk.dependency 'LYTSDK/LYTCommonLib'
    sdk.source_files  = "Classes/LYTCore/*.h", "FrameworkTest/LYTCore/*.a","Classes/LYTCore/ReadMe.md"
    sdk.vendored_libraries = "Classes/LYTCore/*.a"
    sdk.public_header_files = "Classes/LYTCore/*.h"

  end
end
