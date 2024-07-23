Pod::Spec.new do |s|
  s.name             = 'zebra_rfid_reader_sdk'
  s.version          = '0.1.0'
  s.summary          = 'A Flutter plugin for Zebra RFID readers.'
  s.description      = <<-DESC
  This plugin allows Flutter apps to interact with Zebra RFID readers.
  DESC
  s.homepage         = 'https://yourpluginhomepage.com'
  s.license          = { :file => '../LICENSE' }
  s.author           = { 'Your Name' => 'your_email@example.com' }
  s.source           = { :path => '.' }
  s.source_files     = 'Classes/**/*.{h,m,swift}'
  s.static_framework = true
  s.dependency       'Flutter'
  s.platform         = :ios, '14.0'
  s.frameworks       = 'CoreBluetooth', 'ExternalAccessory'

  s.subspec 'symbolrfid-sdk' do |symbolrfid|
    symbolrfid.preserve_paths = 'libraries/symbolrfid-sdk/include/*.h'
    symbolrfid.source_files   = 'libraries/symbolrfid-sdk/include/*'
    symbolrfid.vendored_libraries = 'libraries/symbolrfid-sdk/libsymbolrfid-sdk.a'
    symbolrfid.xcconfig       = { 'HEADER_SEARCH_PATHS' => "${PODS_ROOT}/../.symlinks/plugins/#{s.name}/ios/libraries/symbolrfid-sdk/include" }
  end

  s.info_plist = {
    'UISupportedExternalAccessoryProtocols' => ['com.zebra.rfd8X00_easytext', 'com.zebra.scanner.SSI']
  }

  s.pod_target_xcconfig = { 
    'DEFINES_MODULE' => 'YES',
    'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'i386'
  }
  s.swift_version = '5.0'
end
