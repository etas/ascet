<?xml version='1.0'?>
<!--
  This is an XSLT stylesheet designed for eHandBook Custom attributes used in Dita2Fo Conversion
-->

<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform"
  xmlns:fo="http://www.w3.org/1999/XSL/Format" version="1.1">

	<!-- default attributes for titles -->
	<xsl:attribute-set name="topic.title">
		<xsl:attribute name="color">#164293</xsl:attribute>
		<xsl:attribute name="font-size">1.77em</xsl:attribute>
		<xsl:attribute name="font-family">Calibri, Arial, Cambria, sans-serif</xsl:attribute>
	</xsl:attribute-set>

	<xsl:attribute-set name="topic.topic.title">
		<xsl:attribute name="color">#164293</xsl:attribute>
		<xsl:attribute name="font-size">1.62em</xsl:attribute>
		<xsl:attribute name="font-family">Calibri, Arial, Cambria, sans-serif</xsl:attribute>
	</xsl:attribute-set>
	
	<xsl:attribute-set name="topic.topic.topic.title">
		<xsl:attribute name="color">#164293</xsl:attribute>
		<xsl:attribute name="font-size">1.62em</xsl:attribute>
		<xsl:attribute name="font-family">Calibri, Arial, Cambria, sans-serif</xsl:attribute>
	</xsl:attribute-set> 
	
	<xsl:attribute-set name="topic.topic.topic.topic.title">
		<xsl:attribute name="color">#164293</xsl:attribute>
		<xsl:attribute name="font-size">1.3em</xsl:attribute>
		<xsl:attribute name="font-family">Calibri, Arial, Cambria, sans-serif</xsl:attribute>
	</xsl:attribute-set> 

	<!-- default attributes for header -->
	<xsl:attribute-set name="header_text">
		<xsl:attribute name="font-size">9pt</xsl:attribute>
		<xsl:attribute name="color">#5A646E</xsl:attribute>
		<xsl:attribute name="font-family">Arial, sans-serif</xsl:attribute>
	</xsl:attribute-set>

	<!-- default attributes for header image -->
	<xsl:attribute-set name="header_align">
		<xsl:attribute name="text-align">left</xsl:attribute>
	</xsl:attribute-set>

	<!-- default attributes for footer -->
	<xsl:attribute-set name="footer_text">
		<xsl:attribute name="font-size">9pt</xsl:attribute>
		<xsl:attribute name="color">#5A646E</xsl:attribute>
		<xsl:attribute name="font-family">Arial, sans-serif</xsl:attribute>
	</xsl:attribute-set>

	<!-- default attributes for footer image -->
	<xsl:attribute-set name="footer_align">
		<xsl:attribute name="text-align">left</xsl:attribute>
	</xsl:attribute-set>

	<!-- default attributes for text -->
	<xsl:attribute-set name="p">
		<xsl:attribute name="font-size">10.5pt</xsl:attribute>
		<xsl:attribute name="font-family">Calibri, Arial, Cambria, sans-serif</xsl:attribute>
	</xsl:attribute-set>

	<!-- general table style -->
	<xsl:attribute-set name="table.data">
		<xsl:attribute name="font-family">Calibri, Arial, Cambria, sans-serif</xsl:attribute>
		<xsl:attribute name="font-size">10pt</xsl:attribute>
		<xsl:attribute name="color">#000000</xsl:attribute>
	</xsl:attribute-set>

	<!-- EHANDBOOK generated table style -->
	<xsl:attribute-set name="frameall">
		<xsl:attribute name="font-family">Calibri, Arial, Cambria, sans-serif</xsl:attribute>
	</xsl:attribute-set>

	<!--default color for figure caption-->
	<xsl:attribute-set name="figCaption">
		<xsl:attribute name="color">#000000</xsl:attribute>
	</xsl:attribute-set>

	<!--default color for table caption -->
	<xsl:attribute-set name="tableCaption">
		<xsl:attribute name="color">#000000</xsl:attribute>
		<xsl:attribute name="font-family">Calibri, Arial, Cambria, sans-serif</xsl:attribute>
	</xsl:attribute-set>
	<!--
		Style of header
	-->
	<xsl:attribute-set name="odd__header">
		<xsl:attribute name="text-align">start</xsl:attribute>	
		<xsl:attribute name="padding-left" select="$page-margins-left-right"/>
		<xsl:attribute name="line-height">6mm</xsl:attribute>
		<xsl:attribute name="end-indent">0pt</xsl:attribute> 
		<xsl:attribute name="space-after.conditionality">retain</xsl:attribute>
		<xsl:attribute name="background-color">#5A646E </xsl:attribute>
	</xsl:attribute-set>

	<xsl:attribute-set name="__fo__root">
		<xsl:attribute name="font-family">Calibri, Arial, Cambria, sans-serif</xsl:attribute>
	</xsl:attribute-set>

	<xsl:attribute-set name="custom.title">
		<xsl:attribute name="font-family">Calibri, Arial, Cambria, sans-serif</xsl:attribute>
	</xsl:attribute-set>

</xsl:stylesheet>
