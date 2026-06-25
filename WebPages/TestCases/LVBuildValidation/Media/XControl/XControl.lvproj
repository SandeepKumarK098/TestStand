<?xml version='1.0'?>
<Project Type="Project" LVVersion="8008005">
   <Item Name="My Computer" Type="My Computer">
      <Property Name="CCSymbols" Type="Str">OS,Win;CPU,x86;</Property>
      <Property Name="server.app.propertiesEnabled" Type="Bool">true</Property>
      <Property Name="server.control.propertiesEnabled" Type="Bool">true</Property>
      <Property Name="server.tcp.enabled" Type="Bool">false</Property>
      <Property Name="server.tcp.port" Type="Int">0</Property>
      <Property Name="server.tcp.serviceName" Type="Str">My Computer/VI Server</Property>
      <Property Name="server.tcp.serviceName.default" Type="Str">My Computer/VI Server</Property>
      <Property Name="server.vi.callsEnabled" Type="Bool">true</Property>
      <Property Name="server.vi.propertiesEnabled" Type="Bool">true</Property>
      <Property Name="specify.custom.address" Type="Bool">false</Property>
      <Item Name="Min Max Slider XControl.xctl" Type="XControl" URL="Min Max Slider XControl.xctl">
         <Item Name="Min Max Slider Data.ctl" Type="Ability VI" URL="Min Max Slider Data.ctl"/>
         <Item Name="Min Max Slider State.ctl" Type="Ability VI" URL="Min Max Slider State.ctl"/>
         <Item Name="Min Max Slider Facade.vi" Type="Ability VI" URL="Min Max Slider Facade.vi"/>
         <Item Name="Min Max Slider Init.vi" Type="Ability VI" URL="Min Max Slider Init.vi"/>
      </Item>
      <Item Name="VI with XControl.vi" Type="VI" URL="VI with XControl.vi"/>
      <Item Name="Dependencies" Type="Dependencies"/>
      <Item Name="Build Specifications" Type="Build"/>
   </Item>
</Project>
